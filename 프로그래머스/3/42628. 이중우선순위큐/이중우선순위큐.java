import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        Deque<Integer> dq = new ArrayDeque<>();
        PriorityQueue<Integer> pq1 = new PriorityQueue<>((o1,o2)->o1-o2);
        PriorityQueue<Integer> pq2 = new PriorityQueue<>((o1,o2)->o2-o1);
        List <Integer> answer = new ArrayList<>();
        for(String s : operations){
            int num = 0;
            if(s.charAt(0)=='I'){
                if(s.charAt(2)=='-'){
                    num = -1 * Integer.parseInt(s.substring(3));
                }
                else{
                    num = Integer.parseInt(s.substring(2));
                }
                dq.add(num);
                List<Integer> tempList = new ArrayList<>(dq);
        
                // ArrayList 정렬
                Collections.sort(tempList);
        
                // 정렬된 요소를 다시 ArrayDeque로 복사
                dq.clear();
                dq.addAll(tempList);
            }
            if(s.charAt(0)=='D'){
                if(s.charAt(2)=='-'&&!dq.isEmpty()){
                    dq.removeFirst();
                }
                else{
                    if(!dq.isEmpty()){
                        dq.removeLast();
                    }
                }
            }
        }
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
