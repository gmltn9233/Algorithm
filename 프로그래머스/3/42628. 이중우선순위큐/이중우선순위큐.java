import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        Deque<Integer> dq = new ArrayDeque<>();
        for(String s : operations){
            if(s.charAt(0)=='I'){
                if(s.charAt(2)=='-'){
                    dq.add(-1 * Integer.parseInt(s.substring(3)));
                }
                else{
                    dq.add(Integer.parseInt(s.substring(2)));
                }
                List<Integer> dqList = new ArrayList<>(dq);
                dqList.sort((o1,o2)->o1-o2);
                dq.clear();
                dq.addAll(dqList);
            }
            else{
                if(!dq.isEmpty()){
                    if(s.charAt(2)=='-'){
                        dq.removeFirst();
                    }
                    else{
                        dq.removeLast();
                    }
                }
            }
        }
        List<Integer> answer = new ArrayList<>();
        if(dq.isEmpty()){
            answer.add(0);
            answer.add(0);
        }
        else{
            answer.add(dq.getLast());
            answer.add(dq.getFirst());
        }
        return answer.stream().mapToInt(i->i).toArray();
    }
}