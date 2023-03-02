#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {

    // 하나일 때
    if (citations.size() == 1) {
        return min(citations[0], 1);
    }

    int h = 0;
    bool find = false;
    sort(citations.begin(), citations.end());
    reverse(citations.begin(), citations.end());

    for (int i = 0; i < citations.size() - 1; i++) {
        h = i + 1;
        if (citations[i] >= h && citations[i + 1] <= h) {
            find = true;
            break;
        }
    }

    // 마지막 체크
    if (citations[citations.size() - 1] >= citations.size()) {
        return citations.size();
    }

    if (find) return h;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> input = {3, 0, 6, 1, 5};
    solution(input);
    return 0;
}
