#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    answer.emplace_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        int before = arr[i - 1];
        int curr = arr[i];

        if (before != curr)
            answer.emplace_back(curr);

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
