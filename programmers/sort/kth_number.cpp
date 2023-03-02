#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    for (int c = 0; c < commands.size(); c++) {
        tmp.clear();

        int start = commands[c][0] - 1;
        int end = commands[c][1] - 1;
        int idx = commands[c][2] - 1;

        for (int i = start; i <= end; i++) {
            tmp.emplace_back(array[i]);
        }
        sort(tmp.begin(), tmp.end());
        answer.emplace_back(tmp[idx]);
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
