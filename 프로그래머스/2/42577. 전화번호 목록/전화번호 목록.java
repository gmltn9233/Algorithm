import java.util.*;
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        HashSet<String> a = new HashSet<String>();
        for(String s : phone_book){
            a.add(s);
        }
        for(int i=0; i<phone_book.length; i++){
            for(int j=0; j<phone_book[i].length(); j++){
                if(a.contains(phone_book[i].substring(0,j))){
                    return false;
                }
            }
        }
        return answer;
    }
}