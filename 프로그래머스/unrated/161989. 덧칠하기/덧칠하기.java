class Solution {
    public int solution(int n, int m, int[] section) {
        int[] num= new int[n];
        for(int i=0; i<n; i++){
            num[i]=1;
        }
        for(int i=0; i<section.length; i++){
            num[i]=0;
        }
        int now=0;
        int answer=0;
        for(int i=0; i<section.length; i++){
            if(num[i]==1) continue;
            now=section[i]+m-1;
            for(int j=0; j<section.length; j++){
                if(section[j]<=now){
                    num[j]=1;
                }
            }
            ++answer;
        }
        return answer;
    }
}