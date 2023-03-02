#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C, total;
vector<int> answer;
bool visited[200][200];

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    total = C;

    bfs();
    sort(answer.begin(), answer.end());
    for (int i: answer) {
        cout << i << " ";
    }
    return 0;
}

void bfs() {

    queue<pair<int, int>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        int c = total - (a + b);
        q.pop();

        if (visited[a][b]) continue;
        visited[a][b] = true;

        if (a == 0)
            answer.push_back(c);

        // a -> b
        if (a + b > B) q.emplace(a - (B - b), B);
        else q.emplace(0, a + b);
        // a -> c
        if (a + c > C) q.emplace(a - (C - c), b);
        else q.emplace(0, b);
        // b -> a
        if (a + b > A) q.emplace(A, b - (A - a));
        else q.emplace(a + b, 0);
        // b -> c
        if (b + c > C) q.emplace(a, b - (C - c));
        else q.emplace(a, 0);
        // c -> a
        if (a + c > A) q.emplace(A, b);
        else q.emplace(a + c, b);
        // c -> b
        if (c + b > B) q.emplace(a, B);
        else q.emplace(a, b + c);
    }
}