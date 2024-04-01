import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(arr[0]);
        for(int i=1; i<arr.length; i++){
            if(dq.peekLast()==arr[i]){
                continue;
            }
            else{
                dq.add(arr[i]);
            }
        }
        List<Integer> answer = new ArrayList<>();
        while(dq.peekFirst()!=null){
            answer.add(dq.peekFirst());
            dq.removeFirst();
        }

        return answer.stream().mapToInt(i->i).toArray();
    }
}