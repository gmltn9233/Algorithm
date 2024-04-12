import java.util.*;
class Solution {
    int answer;
    public void dfs(int sum, int idx, int target, int[] numbers){
        if(idx == numbers.length){
            if(sum == target){
                ++answer;
            }
            return;
        }
        dfs(sum+numbers[idx],idx+1,target,numbers);
        dfs(sum-numbers[idx],idx+1,target,numbers);
    }
    public int solution(int[] numbers, int target) {
        dfs(0,0,target,numbers);
        return answer;
    }
}