#include <iostream>
#include <queue>

using namespace std;

int computer, n, c1, c2, cnt = 0;
int net[101][101];
bool visited[101];

void bfs(int x) {

    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        x = q.front();
        q.pop();
        cnt++;

        for (int i = 1; i <= computer; i++) {
            if (net[x][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> computer >> n;

    for (int i = 0; i < n; i++) {
        cin >> c1 >> c2;
        net[c1][c2] = 1;
        net[c2][c1] = 1;
    }

    bfs(1);
    cout << cnt - 1;

    return 0;
}


