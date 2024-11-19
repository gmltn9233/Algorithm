#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int solution(vector<int> nums)
{
    for(int num : nums){
        mp[num] += 1;
    }
    
    return mp.size() < nums.size()/2 ? mp.size() : nums.size()/2;
}