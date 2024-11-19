import java.util.*;
class Solution {
    public int solution(int[] nums) {
        HashSet<Integer> hashSet = new HashSet<Integer>();
        for(int i=0; i<nums.length; i++){
            hashSet.add(nums[i]);
        }
        return hashSet.size()<nums.length/2 ? hashSet.size() : nums.length/2;
    }
}