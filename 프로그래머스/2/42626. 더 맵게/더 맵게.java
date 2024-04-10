import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0; i<scoville.length; i++){
            pq.add(scoville[i]);
        }
        
        while(true){
            if(pq.isEmpty()){
                return -1;
            }
            if(pq.peek()>=K){
                break;
            }
            if(pq.size()==1 && pq.peek()<K){
                answer = -1;
                break;
            }
            if(pq.size()>=2){
                int food1 = pq.poll();
                int food2 = pq.poll();
                pq.add(food1+food2*2);
            }
            ++answer;
        }
        
        return answer;
    }
}