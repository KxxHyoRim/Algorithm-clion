#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int p1[5] = {1, 2, 3, 4, 5};
int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score = {0, 0, 0};
    for (int i = 0; i < answers.size(); i++) {
        int answer = answers[i];
        int num1 = p1[i % 5];
        int num2 = p2[i % 8];
        int num3 = p3[i % 10];
        if (answer == num1) score[0]++;
        if (answer == num2) score[1]++;
        if (answer == num3) score[2]++;
    }
    priority_queue<pair<int, int>> pq;   // 점수, 사람idx
    pq.emplace(score[0], 0);
    pq.emplace(score[1], 1);
    pq.emplace(score[2], 2);

    int max_score = pq.top().first;
    int max_idx = pq.top().second;
    answer.emplace_back(max_idx + 1);
    pq.pop();
    if (pq.top().first == max_score) {
        max_idx = pq.top().second;
        answer.emplace_back(max_idx + 1);
        pq.pop();
        if (pq.top().first == max_score) {
            max_idx = pq.top().second;
            answer.emplace_back(max_idx + 1);
            pq.pop();
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num.txt", "r", stdin);

    return 0;
}
