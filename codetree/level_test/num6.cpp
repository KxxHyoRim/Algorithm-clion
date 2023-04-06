#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[1001][1001];
int sum[1001][1001];

int dx[2] = {0, 1}; // 상, 우
int dy[2] = {-1, 0};

bool isInMap(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.emplace(x, y);
    sum[n - 1][0] = map[n - 1][0];

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 2; i++) { // 위, 오른쪽 두가지
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isInMap(nx, ny)) {
                q.emplace(nx, ny);
                sum[ny][nx] = max(sum[ny][nx], sum[y][x] + map[ny][nx]);
            }
        }
    }
    return sum[0][n - 1];
}

int main() {

    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    int sx = 0, sy = n - 1, ex = n - 1, ey = 0;

    cout << bfs(sx, sy);

    return 0;
}