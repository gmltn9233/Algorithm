#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> genre;
map<string, vector<pair<int,int>>> music;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a<b; 
    else return a.first >b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    for (int i =0; i<n; i++){
        genre[genres[i]]+= plays[i];
        music[genres[i]].push_back(make_pair(plays[i],i));
    }
    
    // genre 정렬
    vector<pair<int,string>> sorted_genre;
    for(auto at : genre){
        sorted_genre.push_back({at.second, at.first});
    }
    
    sort(sorted_genre.begin(),sorted_genre.end());
    reverse(sorted_genre.begin(),sorted_genre.end());
    
    
    // 장르별 노래 정렬
    for(int i=0; i<sorted_genre.size(); i++){
        vector<pair<int,int>> v = music[sorted_genre[i].second];
        sort(v.begin(), v.end(), cmp);
        answer.push_back(v[0].second);
        if(v.size()>=2){
            answer.push_back(v[1].second);
        }
    }
    
    
    return answer;
}
// 1. 노래 재생수 합이 큰 장르 먼저 수록
// 2. 장르 내에서 많이 재생된 노래 먼저 수록
// 3. 재생 횟수가 같다면 고유번호가 낮은 노래 먼저 수록