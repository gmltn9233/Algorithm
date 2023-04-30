class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int [][] matrix=new int[rows][columns];
        int num=1;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                matrix[i][j]=num;
                num++;
            }
        }
        int [] answer=new int[queries.length];
        for(int i=0; i<queries.length;i++){
            int y1=queries[i][0]-1;
            int x1=queries[i][1]-1;
            int y2=queries[i][2]-1;
            int x2=queries[i][3]-1;
            int min=Integer.MAX_VALUE;
            int temp=matrix[y1][x1];
            min=Math.min(min,temp);
            for(int j=x1+1; j<=x2; j++){
                int value=matrix[y1][j];
                matrix[y1][j]=temp;
                temp=value;
                min=Math.min(min,temp);
            }//top
            for(int j=y1+1; j<=y2; j++){
                int value=matrix[j][x2];
                matrix[j][x2]=temp;
                temp=value;
                min=Math.min(min,temp);
            }//right
            for(int j=x2-1; j>=x1; j--){
                int value=matrix[y2][j];
                matrix[y2][j]=temp;
                temp=value;
                min=Math.min(min,temp);
            }//bottom
            for(int j=y2-1; j>=y1; j--){
                int value=matrix[j][x1];
                matrix[j][x1]=temp;
                temp=value;
                min=Math.min(min,temp);
            }//left
            answer[i]=min;
        }
        return answer;
    }
}