#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
vector<vector<int>> board;
queue<int> moves;
stack<int> basket;
int n, answer;

void init(vector<vector<int>> b, vector<int> m) {
    n = b.size();

    board.resize(b.size());
    for (int y = 0; y < b.size(); y++) {
        for (int x = 0; x < b.size(); x++) {
            board[y].emplace_back(b[y][x]);
        }
    }

    for (int i = 0; i < m.size(); i++) {
        moves.emplace(m[i] - 1);
    }
}

int getCrainPos() {
    if (!moves.empty()) {
        int rtn = moves.front();
        moves.pop();
        return rtn;
    }
    return -1;
}

int pickDoll(int x) {
    for (int y = 0; y < n; y++) {
        if (board[y][x] == 0) continue;
        int rtn = board[y][x];
        board[y][x] = 0;
        return rtn;
    }
    return -1;
}

void putBasket(int doll) {
    if (basket.empty()) {// 그냥 넣기
        basket.emplace(doll);
        return;
    }

    int top = basket.top();
    if (top == doll) {
        answer += 2;
        basket.pop();
    } else {
        basket.emplace(doll);
    }
}

int solution(vector<vector<int>> b, vector<int> m) {

    init(b, m);
    for (int i = 0; i < m.size(); i++) {
        int crain_pos = getCrainPos();
        int doll = pickDoll(crain_pos);
        if (doll != -1)
            putBasket(doll);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<vector<int>> b = {{0, 0, 0, 0, 0},
                             {0, 0, 1, 0, 3},
                             {0, 2, 5, 0, 1},
                             {4, 2, 4, 4, 2},
                             {3, 5, 1, 3, 1}};
    vector<int> m = {1, 5, 3, 5, 1, 2, 1, 4};
    solution(b, m);

    return 0;
}
