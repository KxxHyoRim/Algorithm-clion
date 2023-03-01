#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

/*
 * priority_queue<pair<int,int>> -> 첫번째, 두번째 값을 기준으로 내림차순 정렬
 * map<string, p_q> 조합도 쓸수있음!
 * vector<pair<int, string>> 형태도 sort, reverse 할 수 있다
 * */

vector<int> solution(vector<string> genres, vector<int> plays) {

    vector<int> answer;
    map<string, int> m;  // 장르별 재생횟수
    map<string, priority_queue<pair<int, int>>> m1; // <장르별, <횟수, 고유번호>>
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
        m1[genres[i]].emplace(plays[i], -i);    // 고유번호가 낮은것부터 정렬하기 위해 -
    }

    vector<pair<int, string>> play_num(m.size());

    int i = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        play_num[i].first = it->second;
        play_num[i++].second = it->first;
    }

    sort(play_num.begin(), play_num.end());
    reverse(play_num.begin(), play_num.end());

    for (i = 0; i < play_num.size(); i++) {
        string genre = play_num[i].second;
        int first = -m1[genre].top().second;
        m1[genre].pop();
        answer.push_back(first);
        int second;
        if (!m1[genre].empty()) {
            second = -m1[genre].top().second;
            answer.push_back(second);
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    solution(genres, plays);

    return 0;
}
