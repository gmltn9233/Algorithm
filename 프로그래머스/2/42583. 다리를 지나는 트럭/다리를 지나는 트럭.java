import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Deque<Integer> dq = new ArrayDeque<>();
        int time=0,index=0,sum=0;
        int[] t = new int[10004];
        while(true){
            if(index==truck_weights.length && dq.isEmpty()){
                break;
            }
            if(!dq.isEmpty()){
                int last = dq.getLast();
                if(t[last]+bridge_length <= time){
                sum -= truck_weights[last];
                dq.pollLast();
                }
            }
            if(index<truck_weights.length&&sum+truck_weights[index]<=weight&&dq.size()<=bridge_length){
                sum += truck_weights[index];
                dq.addFirst(index);
                t[index++]=time;
            }
            ++time;
        }
        return time;
    }
}