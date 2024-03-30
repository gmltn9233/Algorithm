import java.util.*;
class Solution {
    public int[] solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();
        HashMap<String,Integer> totalMap = new HashMap<>();
        HashMap<String,Map<Integer,Integer>> maps = new HashMap<>();
        int n = genres.length;
        for(String s : genres){
            maps.put(s,new HashMap<>());
        }
        for(int i=0; i<n; i++){
            totalMap.put(genres[i],totalMap.getOrDefault(genres[i],0)+plays[i]);
            maps.get(genres[i]).put(i,plays[i]);
        }
        List<String> keySetList = new ArrayList<>(totalMap.keySet());
        keySetList.sort((o1, o2) -> (totalMap.get(o2).compareTo(totalMap.get(o1))));
        keySetList.forEach(s -> {
            Map<Integer, Integer> asdf = maps.get(s);

            List<Integer> integers = new ArrayList<>(asdf.keySet());

            integers.sort((o1, o2) -> (asdf.get(o2).compareTo(asdf.get(o1))));

            if (integers.size() <= 1) {
                answer.add(integers.get(0));
            } else {
                answer.add(integers.get(0));
                answer.add(integers.get(1));
            }
        });
        return answer.stream().mapToInt(i -> i).toArray();
    }
}
