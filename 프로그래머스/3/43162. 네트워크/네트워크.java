import java.util.*;
class Solution {
    int answer;
    int[] visited = new int[201];
    public void dfs(int idx,int[][] computers){
        visited[idx] = 1;
        for(int i=0; i<computers[idx].length; i++){
            if(computers[idx][i]==1 && visited[i]==0){
                dfs(i,computers);
            }
        }
    }
    public int solution(int n, int[][] computers) {
        for(int i=0; i<computers.length; i++){
            if(visited[i]==0){
                dfs(i,computers);
                ++answer;
            }
        }
        return answer;
    }
}