class Solution {
    static int[] dy={-1,0,1,0};
    static int[] dx={0,1,0,-1};
    static boolean[][] visited;
    static int[] answer;
    
    public void dfs(int num, int y, int x, int count , String[] places){
        if(count>2) return;
        if(count>0&&count<=2 &&places[y].charAt(x)=='P'){
            answer[num]=0;
            return;
        }
        for(int i=0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||nx<0||ny>=5||nx>=5) continue;
            if(visited[ny][nx]||places[ny].charAt(nx)=='X') continue;
            visited[ny][nx]=true;
            dfs(num,ny,nx,count+1,places);
            visited[ny][nx]=false;
        }
    }
    
    public int[] solution(String[][] places) {
        answer= new int[places.length];
        for(int i=0; i<5; i++){
            answer[i]=1;
        }
        for(int i=0; i<places.length; i++){
            visited= new boolean[5][5];
            for(int j=0; j<5; j++){
                for(int k=0; k<5; k++){
                    if(places[i][j].charAt(k)=='P'){
                        visited[j][k]=true;
                        dfs(i,j,k,0,places[i]);
                        visited[j][k]=false;
                    }
                }
            }
        }
        return answer;
    }
}