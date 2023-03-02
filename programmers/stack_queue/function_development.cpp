#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    int releaseIdx = 0;

    while (releaseIdx < n) {
        for (int i = 0; i < n; i++) {
            progresses[i] = min(100, progresses[i] + speeds[i]);
        }
        int cnt = 0;
        while (progresses[releaseIdx] == 100) {
            cnt++;
            releaseIdx++;
        }
        if (cnt > 0)
            answer.emplace_back(cnt);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    solution(progresses, speeds);

    return 0;
}
