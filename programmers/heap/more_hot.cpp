#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {

    priority_queue<int> pq;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(-scoville[i]);
    }
    int idx = 0;
    while (!pq.empty()) {
        int first = -1, second = -1;
        if (!pq.empty()) {
            first = -pq.top();
            pq.pop();
            if (first >= K) break;
        }
        if (!pq.empty()) {
            second = -pq.top();
            pq.pop();
        } else {
            return -1;
        }

        int newFood = first + (second * 2);
        idx++;

        pq.push(-newFood);
    }

    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution(vector<int>{1, 2, 3, 9, 10, 12}, 7);

    return 0;
}
