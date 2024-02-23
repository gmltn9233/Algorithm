#include <bits/stdc++.h>
using namespace std;
int ret;
void dfs(vector<int> numbers,int target, int index, int total){
    if(index==numbers.size()){
        if(total==target){
            ++ret;
        }
        return;
    }
    int sum1= total+numbers[index];
    int sum2= total-numbers[index];
    index++;
    dfs(numbers,target,index,sum1);
    dfs(numbers,target,index,sum2);
    return;
}
int solution(vector<int> numbers, int target) {
    dfs(numbers,target,0,0);
    return ret;
}