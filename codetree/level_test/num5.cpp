#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int map[101][101];
bool visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isInMap(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs(int x, int y) {
    int rtn = 0;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[y][x] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        rtn++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInMap(nx, ny)) {
                if (!visited[ny][nx] && map[ny][nx] != 0) {
                    //queue에 집어넣기
                    q.emplace(nx, ny);
                    visited[ny][nx] = true;
                }
            }
        }
    }
    return rtn;

}

int main() {
    cin >> n;
    int ax, ay, bx, by;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
            if (map[y][x] == 2) { // A가 사는 곳
                ax = x;
                ay = y;
            }
            if (map[y][x] == 3) { // b가 사는곳
                bx = x;
                by = y;
            }
        }
    }

    cout << bfs(ax, ay) << " " << bfs(bx, by);


    return 0;
}