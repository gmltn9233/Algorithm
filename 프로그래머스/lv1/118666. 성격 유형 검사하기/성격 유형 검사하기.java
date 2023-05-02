class Solution {
    public String solution(String[] survey, int[] choices) {
        char[] mbti={'R','T','C','F','J','M','A','N'};
        int[] num={0,0,0,0,0,0,0,0}; 
        StringBuilder sb=new StringBuilder();
        for(int i=0; i<survey.length; i++){
            char fst=survey[i].charAt(0);
            char sec=survey[i].charAt(1);
            if(choices[i]==1){
                for(int j=0; j<8; j++){
                    if(mbti[j]==fst){
                        num[j]+=3;
                    }
                }
            }
            else if (choices[i]==2){
                for(int j=0; j<8; j++){
                    if(mbti[j]==fst){
                        num[j]+=2;
                    }
                }
            }
            else if (choices[i]==3){
                for(int j=0; j<8; j++){
                    if(mbti[j]==fst){
                        num[j]+=1;
                    }
                }
            }
            else if (choices[i]==5){
                for(int j=0; j<8; j++){
                    if(mbti[j]==sec){
                        num[j]+=1;
                    }
                }
            }
            else if (choices[i]==6){
                for(int j=0; j<8; j++){
                    if(mbti[j]==sec){
                        num[j]+=2;
                    }
                }
            }
            else if (choices[i]==7){
                for(int j=0; j<8; j++){
                    if(mbti[j]==sec){
                        num[j]+=3;
                    }
                }
            }
        }
        for(int i=0; i<8; i+=2){
            if(num[i]>=num[i+1]) sb.append(mbti[i]);
            else{
                sb.append(mbti[i+1]);
            }
        }
        String answer=sb.toString();
        
        return answer;
    }
}