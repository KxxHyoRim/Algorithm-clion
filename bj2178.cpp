#include <iostream>
#include <queue>

using namespace std;

/* 최단거리 문제는, distance를 저장할 수 있는 배열을 별도로 만들어 주자!
 * */

int n, m, result = 0;
int map[100][100];
int visited[100][100];
int dist[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        string oneLine;
        cin >> oneLine;
        for (int x = 0; x < m; x++) {
            int tmp = (oneLine[x] == '1') ? 1 : 0;
            map[y][x] = tmp;
        }
    }

    bfs(0, 0);
    cout << dist[n - 1][m - 1];
    return 0;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[y][x] = true;
    dist[y][x] = 1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        result++;
        if (x == m && y == n) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (map[ny][nx] == 1 && !visited[ny][nx]) {
                    q.emplace(nx, ny);
                    visited[ny][nx] = true;
                    dist[ny][nx] = dist[y][x] + 1;
                }
            }
        }
    }
}

