#include <bits/stdc++.h>
using namespace std;
map<int,int> mpp;
int solution(vector<int> nums)
{
    for(int num : nums){
        mpp[num] += 1;
    }
    
    return mpp.size() < nums.size()/2 ? mpp.size() : nums.size()/2;
}