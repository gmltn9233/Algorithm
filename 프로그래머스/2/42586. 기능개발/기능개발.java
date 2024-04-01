import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Deque<Integer> dq = new ArrayDeque<>();
        for(int i=0; i<progresses.length; i++){
            int num = (100-progresses[i])%speeds[i]==0 ? (100-progresses[i])/speeds[i] : (100-progresses[i])/speeds[i] + 1;
            dq.add(num);
        }
        List<Integer> answer = new ArrayList<>();
        int max = dq.pollFirst();
        System.out.println(max);
        int cnt=1;
        while(!dq.isEmpty()){
            int firstNum = dq.pollFirst();
            System.out.println(firstNum);
            if(firstNum>max){
                max=firstNum;
                answer.add(cnt);
                cnt=0;
            }
            cnt ++;
        }
        answer.add(cnt);
        return answer.stream().mapToInt(i->i).toArray();
    }
}