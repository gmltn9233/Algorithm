#include <bits/stdc++.h> 
using namespace std;

int solution(string s) {
    int ret = s.size();
    for(int cnt = 1; cnt <= s.size()/2; cnt++){  
        vector<string> v;  
        bool flag = 0; 
        int j = 0; 
        while(true){
            if(j + cnt >= s.size()){
                v.push_back(s.substr(j, s.size() - j));
                break;
            }
            v.push_back(s.substr(j, cnt));
            j = j + cnt;
        }
        int _ret = s.size();
        string temp = v[0];
        int _count = 1; 
        for(int i = 1; i < (int)v.size(); i++){
            if(temp == v[i])_count++;
            else{
                if(_count != 1)_ret = _ret - (temp.size() * (_count - 1)) + to_string(_count).size();
                _count = 1; 
                temp = v[i];
            }
            if(i == v.size() - 1 && _count != 1) _ret = _ret - (temp.size() * (_count - 1)) + to_string(_count).size(); 
        }  
        ret = min(ret, _ret);
    }
    return ret;
}
