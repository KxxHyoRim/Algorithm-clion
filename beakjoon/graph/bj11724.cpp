#include <iostream>
#include <queue>

using namespace std;

int n, m, u, v, cnt = 0;
int map[1001][1001];
bool visited[1001];

void bfs(int x) {
    queue<int> q;
    visited[x] = true;
    q.emplace(x);

    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (map[x][i] == 1 && !visited[i]) {
                q.emplace(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
