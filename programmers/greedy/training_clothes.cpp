#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 주의 : 학생 index 1 ~ n까지이다!
    int answer = 0;

    vector<int> state(n + 1);

    for (int i = 0; i < lost.size(); i++) {
        state[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        state[reserve[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (state[i] == -1) {
            \
            // 앞사람한테 빌릴 수 있음
            if (i - 1 > 0 && state[i - 1] >= 1) {
                state[i - 1]--;
                state[i]++;
            }
                // 뒷사람한테 빌릴 수 있음
            else if (i + 1 <= n && state[i + 1] >= 1) {
                state[i]++;
                state[i + 1]--;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (state[i] >= 0) answer++;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num.txt", "r", stdin);

    return 0;
}
