import java.util.*;
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Deque<Character> dq = new ArrayDeque<>();
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) ==')' && !dq.isEmpty()){
                if(dq.getLast() =='('){
                    dq.removeLast();
                }
            }
            else{
                dq.add(s.charAt(i));
            }
        }
        if(!dq.isEmpty()){
            answer = false;
        }

        return answer;
    }
}