#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {

    int total_time = 0;

    sort(jobs.begin(), jobs.end()); //요청시간, 소요시간 기준 정렬

    int n = jobs.size();
    priority_queue<pair<int, int>> pq; // <소요시간,요청시간>

    pq.emplace(-jobs[0][1], -jobs[0][0]);
    int curr_time = jobs[0][0]; //첫번째 요청을 시작으로 설정
    int jobIdx = 1;

    while (!pq.empty()) {
        pair<int, int> job = pq.top();
        int start_time = curr_time;
        if (start_time < -job.second)
            start_time = -job.second;
        int end_time = curr_time - job.first;
        int process = end_time + job.second;
        total_time += process;
        curr_time = end_time;
        pq.pop();


        // 주의! 같은시간에 들어오는 job이 여러개일수있음! -> while문 처리
        for (int i = start_time; i <= end_time; i++) {
            while (jobIdx < n && jobs[jobIdx][0] == i) {
                pq.emplace(-jobs[jobIdx][1], -jobs[jobIdx][0]);
                jobIdx++;
            }
        }

        if (pq.empty() && jobIdx < n) {
            curr_time = jobs[jobIdx][0]; // 다음 요청시간
            pq.emplace(-jobs[jobIdx][1], -jobs[jobIdx][0]);
            jobIdx++;
        }
    }
    return total_time / n;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> jobs = {{0, 3},
                                {1, 9},
                                {2, 6}};

    vector<vector<int>> jobs2 = {{0, 9},
                                 {0, 4},
                                 {0, 5},
                                 {0, 7},
                                 {0, 3}};
    cout << solution(jobs2);
    return 0;
}
