import java.util.*;
class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        int idx = 0;
        int cnt = 0;
        int end = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1,o2)->o1[1]-o2[1]);
        Arrays.sort(jobs,(o1,o2)-> o1[0]-o2[0]);
        while(cnt<jobs.length){
            while(idx<jobs.length && end>=jobs[idx][0]){
                pq.add(jobs[idx++]);
                // pq에 들어가있는거 end 보다 start가 더 작을경우 pq에 add
            }
            if(pq.isEmpty()){ // 비어있다면 end 갱신
                end = jobs[idx][0];
            }
            else{
                int[] arr = pq.poll();
                answer += arr[1]-arr[0]+end;
                end += arr[1];
                ++cnt;
            }
        }
        return answer/jobs.length;
    }
}