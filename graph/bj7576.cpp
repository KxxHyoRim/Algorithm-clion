#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1000][1000];
queue<pair<int, int>> q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs() {

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (map[ny][nx] == 0) {
                    map[ny][nx] = map[y][x] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
            if (map[y][x] == 1) { q.emplace(x, y); }
        }
    }

    bfs();

    int result, max = 1;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 0) {
                cout << -1;
                return 0;
            }
            if (map[y][x] > max) {
                max = map[y][x];
            }
        }
    }

    if (max == 1) result = 0;
    else result = max - 1;

    cout << result;

    return 0;
}
