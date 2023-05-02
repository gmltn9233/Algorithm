class Solution {
    public int solution(String s) {
        StringBuilder c_an=new StringBuilder();
        for(int i=0; i<s.length();i++){
            char c=s.charAt(i);
            if (c>='0'&&c<='9'){
                c_an.append(c);
            }
            else{
                if(c=='z'){
                    c_an.append('0');
                    i+=3;
                }
                else if (c=='o') {
                    c_an.append('1');
                    i+=2;
                }
                else if (c=='t') {
                    if(s.charAt(i+1)=='w'){
                        c_an.append('2');
                        i+=2;
                    }
                    else if (s.charAt(i+1)=='h'){
                        c_an.append('3');
                        i+=4;
                    }
                }
                else if (c=='f') {
                    if(s.charAt(i+1)=='o'){
                        c_an.append('4');
                        i+=3;
                    }
                    else if (s.charAt(i+1)=='i'){
                        c_an.append('5');
                        i+=3;
                    }
                }
                else if (c=='s') {
                    if(s.charAt(i+1)=='i'){
                        c_an.append('6');
                        i+=2;
                    }
                    else if (s.charAt(i+1)=='e'){
                        c_an.append('7');
                        i+=4;
                    }
                }
                else if (c=='e') {
                    c_an.append('8');
                    i+=4;
                }
                else if (c=='n') {
                    c_an.append('9');
                    i+=3;
                }
            }
        }
        int answer = Integer.parseInt(c_an.toString());
        return answer;
    }
}