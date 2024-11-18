import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
       HashMap<String, Integer> map = new HashMap<String,Integer>();
        for(String s : participant){
            map.put(s,map.getOrDefault(s,0)+1);
        }
        for(String s : completion){
            if(map.get(s)==1){
                map.remove(s);
            }
            else{
                map.replace(s,map.get(s)-1);
            }
        }
        Set<String> S = map.keySet();
        for(String s : S){
            answer += s;
        }
        return answer;
    }
}