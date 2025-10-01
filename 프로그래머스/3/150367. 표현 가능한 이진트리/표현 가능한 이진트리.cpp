#include <bits/stdc++.h>

using namespace std;

string toDigit(long long number){
    string s = "";
    while(number){
        if(number%2) s+='1';
        else s+='0';
        number/=2;
    }
    reverse(s.begin(),s.end());
    int len = 1;
    while(len < s.size()){
        len = len*2 +1;
    }
    while(len > s.size()){
        s = '0' + s;
    }
    return s;
}

bool checkBinaryTree(string s){
    int root = s.size()/2;
    if(s.size()==1) return true;
    string left = s.substr(0,root);
    string right = s.substr(root+1);
    if(s[root]=='0'){
        if(left.find('1') != string::npos || right.find('1') != string::npos){
            return false;
        }
    }
    if(!checkBinaryTree(left) || !checkBinaryTree(right)) return false;
    return true;
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto number : numbers){
        //cout<<number<<"-------------\n";
        if(checkBinaryTree(toDigit(number))){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        }
    }
    return answer;
}
 
// 2진수 변환하고 짝수개면 앞에 0 추가
// 중간이면 불가
// 하위노드가 존재하는데 상위 노드가 존재하면 불가능

// 42 -> 0101010
// 5 -> 101
// 95 -> 1011111
// 이진트리로 표현할 수 있는지 없는지 어떻게 알지

