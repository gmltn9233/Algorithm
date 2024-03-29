import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> a = new HashMap<String,Integer>();
        for(String s: participant){
            a.put(s,a.getOrDefault(s,0)+1);
        }
        for(String s:completion){
            if(a.get(s)==1){
                a.remove(s);
            }
            else{
                a.replace(s,a.get(s)-1);
            }
        }
        Set<String> S = a.keySet();
        for(String s: S){
            answer = s;
        }
        return answer;
    }
}