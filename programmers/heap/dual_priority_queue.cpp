#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int> min_heap;

void clearHeap() {
    while (!max_heap.empty()) max_heap.pop();
    while (!min_heap.empty()) min_heap.pop();
}


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0;

    for (int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if (op == 'I') {
            cout << num << endl;
            max_heap.push(num);
            min_heap.push(-num);
            cnt++;
        } else if (op == 'D' && num == 1) {
            if (cnt == 0) continue;
            max_heap.pop();
            cnt--;
        } else if (op == 'D' && num == -1) {
            if (cnt == 0) continue;
            min_heap.pop();
            cnt--;
        }

        if (cnt == 0) clearHeap();
    }

    if (cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(max_heap.top());
        answer.push_back(-min_heap.top());
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> op1 = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    vector<string> op2 = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
    solution(op2);

    return 0;
}
