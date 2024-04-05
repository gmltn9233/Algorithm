import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        HashMap<Integer,Integer> map = new HashMap<>();
        Deque<Integer>dq = new ArrayDeque<>();
        for(int i=0; i<priorities.length; i++){
            map.put(i,priorities[i]);
            dq.add(i);
        }
        while(!dq.isEmpty()){
            int index = dq.getFirst();
            int num = map.get(index);
            boolean flag = false;
            for(int i=0; i<priorities.length; i++){
                if(num<priorities[i]){
                    dq.removeFirst();
                    dq.add(index);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                priorities[index]=0;
                dq.removeFirst();
                ++answer;
                if(index == location){
                    return answer;
                }
            }
        }
        return answer;
    }
}