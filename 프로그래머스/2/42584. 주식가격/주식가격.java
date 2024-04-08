import java.util.*;
class Solution {
    public List solution(int[] prices) {
        List<Integer> answer = new ArrayList<>();
        for(int i=0; i<prices.length; i++){
            int num = prices.length-1-i;
            for(int j=i+1; j<prices.length; j++){
                if(prices[i]>prices[j]){
                    num = j-i;
                    break;
                }
            }
            answer.add(num);
        }
        return answer;
    }
}