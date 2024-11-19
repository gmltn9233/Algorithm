#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> genreMap; // 장르별 총 재생 수
    map<string, vector<pair<int, int>>> idxMap; // 장르별 (인덱스, 재생 수)
    vector<int> answer;

    // 데이터 입력
    for (int i = 0; i < genres.size(); i++) {
        genreMap[genres[i]] += plays[i];
        idxMap[genres[i]].push_back({i, plays[i]});
    }

    // 장르를 재생 수 기준으로 내림차순 정렬
    vector<pair<int, string>> sortedGenres;
    for (auto &entry : genreMap) {
        sortedGenres.push_back({entry.second, entry.first});
    }
    sort(sortedGenres.rbegin(), sortedGenres.rend()); // 내림차순 정렬

    // 각 장르별로 곡을 정렬하고 최대 2개를 선택
    for (auto &genre : sortedGenres) {
        string genreName = genre.second;
        auto &songs = idxMap[genreName];

        // 곡을 재생 수가 높은 순으로, 재생 수가 같으면 인덱스가 낮은 순으로 정렬
        sort(songs.begin(), songs.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first; // 재생 수가 같으면 인덱스가 낮은 순
            }
            return a.second > b.second; // 재생 수가 높은 순
        });

        // 최대 두 곡 추가
        for (int i = 0; i < min(2, (int)songs.size()); i++) {
            answer.push_back(songs[i].first);
        }
    }

    return answer;
}
