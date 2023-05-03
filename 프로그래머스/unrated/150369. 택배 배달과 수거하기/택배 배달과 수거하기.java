class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        int dpointer=n-1;
        int ppointer=n-1;
        long answer=0;
        while(dpointer>=0||ppointer>=0){
            while(dpointer>=0&&deliveries[dpointer]==0) --dpointer;
            while(ppointer>=0&&pickups[ppointer]==0) --ppointer;
            answer+=(Math.max(dpointer,ppointer)+1)*2;
            int sum=0;
            while(dpointer>=0&&cap>sum){
                sum+=deliveries[dpointer];
                deliveries[dpointer--]=0;
            }
            if(cap<sum){
                deliveries[++dpointer]=sum-cap;
            }
            sum=0;
            while(ppointer>=0&&cap>sum){
                sum+=pickups[ppointer];
                pickups[ppointer--]=0;
            }
            if(cap<sum){
                pickups[++ppointer]=sum-cap;
            }
        }
        return answer;
    }
}