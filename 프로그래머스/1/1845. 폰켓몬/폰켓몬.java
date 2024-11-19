import java.util.*;
class Solution {
    public int solution(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0; i<nums.length; i++){
            map.put(nums[i],map.getOrDefault(nums[i],0)+1);
        }
        Set<Integer> set = map.keySet();
    
        return set.size()<nums.length/2 ? set.size() : nums.length/2;
    }
}