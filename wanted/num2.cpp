#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[y][x] = true;
    int rtn = 1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            if (nx < 0) {
                nx = m + nx;
            } else if (nx >= m) {
                nx = nx - m;
            }
            int ny = y + dy[i];
            if (ny < 0) {
                ny = n + ny;
            } else if (ny >= n) {
                ny = ny - n;
            }

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (map[ny][nx] == 0 && !visited[ny][nx]) {
                    q.emplace(nx, ny);
                    visited[ny][nx] = true;
                    rtn++;
                }
            }
        }
    }

    return rtn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }

    int result = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 0 && !visited[y][x]) {
                bfs(x, y);
                result++;
            }

        }
    }

    cout << result;

    return 0;
}
