#include <bits/stdc++.h>
using namespace std;

int convert(string s){
    return (10*(s[0]-'0')+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
}

string reconvert(int num){
    string hour = to_string(num/60);
    string minute = to_string(num%60);
    if(hour.size()==1){
        hour = '0'+hour;
    }
    if(minute.size()==1){
        minute = '0'+minute;
    }
    return hour+":"+minute;
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int converted_video_len = convert(video_len);
    int converted_op_start = convert(op_start);
    int converted_op_end = convert(op_end);
    int converted_pos = convert(pos);
    cout<<converted_pos<<"\n";
    if(converted_pos >= converted_op_start && converted_pos <= converted_op_end){
        converted_pos = converted_op_end;
    }
    
    for(string command : commands){
        if(command=="next"){
            converted_pos+=10;
            if(converted_pos > converted_video_len){
                converted_pos = converted_video_len;
            }
        }
        if(command=="prev"){
            converted_pos-=10;
            if(converted_pos < 0){
                converted_pos = 0;
            }
            
        }
        if(converted_pos >= converted_op_start && converted_pos <= converted_op_end){
            converted_pos = converted_op_end;
        }
    }
    cout<<converted_pos;
    return reconvert(converted_pos);
}

// 1. 10초 전으로 이동
// 2. 10초 후로 이동
// 3. 오프닝 건너뛰기