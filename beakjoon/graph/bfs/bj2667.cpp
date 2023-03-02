#include <iostream>
#include <queue>

using namespace std;

int n;
int map[25][25];
bool visited[25][25];
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
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (map[ny][nx] == 1 && !visited[ny][nx]) {
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

    cin >> n;

    for (int y = 0; y < n; y++) {
        string tmp;
        cin >> tmp;
        for (int x = 0; x < n; x++) {
            map[y][x] = (tmp[x] == '0') ? 0 : 1;
        }
    }

    priority_queue<int> pq;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] == 1 && !visited[y][x])
                pq.push(-bfs(x, y));
        }
    }

    int size = (int) pq.size();
    cout << size << "\n";
    for (int i = 0; i < size; i++) {
        cout << -pq.top() << "\n";
        pq.pop();
    }

    // 아니.. 위에 코드로 하면 잘 출력되는데, 아래 코드로 하면 출력이 안됨
    // 대체 무엇이 문제인지 알수가 없음
//    cout << pq.size() << "\n";
//    for (int i = 0; i < pq.size(); i++) {
//        cout << -pq.top() << "\n";
//        pq.pop();
//    }

    return 0;
}
