import java.util.*;
class Solution {
    int answer = 0;
    boolean visited[];
    public void dfs(String begin, String target, String[] words, int cnt){
        if(begin.equals(target)){
            answer = cnt;
            return;
        }
        for(int i=0; i<words.length; i++){
            if(visited[i]) continue;
            int same = 0;
            for(int j=0; j<words[i].length(); j++){
                if(begin.charAt(j)==words[i].charAt(j)){
                    ++same;
                }
            }
            if(same == begin.length()-1){
                visited[i] = true;
                dfs(words[i],target,words,cnt+1);
                visited[i] = false;
            }
        }
    }
    public int solution(String begin, String target, String[] words) {
        visited = new boolean[words.length];
        dfs(begin,target,words,0);
        return answer;
    }
}