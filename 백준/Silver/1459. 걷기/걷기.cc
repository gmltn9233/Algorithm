#include <bits/stdc++.h>
using namespace std;
long long x,y,w,s;
long long a,ret;
int main() {
	cin>>x>>y>>w>>s;
	int minDistance = min(x,y);
	int maxDistance = max(x,y);
	int diff = maxDistance - minDistance;
	// 최대 대각선 이동 후 길 이동
	a = minDistance*s+ diff*w;
	ret = a;
	// 최대 대각선 이동 후 대각선 이동
	a = minDistance*s + (diff/2)*2*s + (diff%2)*w;
	ret = min(ret,a);
	// 길로만 이동
	a = (x+y)*w;
	ret = min (ret,a);
	// 최대한 대각선 이용
	a = (x/2)*2*s + (x%2)*w + (y/2)*2*s + (y%2)*w;
	ret = min(ret,a);
	cout<< ret;
	return 0;
}