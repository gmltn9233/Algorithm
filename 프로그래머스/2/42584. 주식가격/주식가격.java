import java.util.*;
class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Deque<Integer> dq = new ArrayDeque<>();
        for(int i=0; i<prices.length; i++){
            while(!dq.isEmpty()&&prices[dq.getLast()]>prices[i]){
                answer[dq.getLast()]=i-dq.getLast();
                dq.removeLast();
            }
            dq.add(i);
        }
        while(!dq.isEmpty()){
            answer[dq.getLast()]=prices.length-dq.getLast()-1;
            dq.removeLast();
        }
        return answer;
    }
}