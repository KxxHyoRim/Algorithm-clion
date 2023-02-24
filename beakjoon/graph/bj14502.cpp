#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int originMap[8][8];
int tempMap[8][8];
int visited[8][8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<int> pos;
vector<bool> wall;

struct Point {
    int x, y;

    Point(int X, int Y) : x(X), y(Y) {}
};

vector<vector<Point>> getWall() {

    pos.resize(n * m);
    wall.resize(n * m);

    for (int i = 0; i < n * m; i++) {
        // 세울 벽 조합 만들기
        pos[i] = i;
        wall[i] = (i > m * n - 4);
    }

    vector<vector<Point>> w;

    do {
        vector<Point> temp;
        for (int i = 0; i < (int) pos.size(); i++) {
            if (wall[i]) {
                temp.emplace_back(i % m, i / m);
            }
        }
        w.push_back(temp);
    } while (next_permutation(wall.begin(), wall.end()));

    return w;
}

void getMap() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> originMap[y][x];
        }
    }
}

void copyMap() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            tempMap[y][x] = originMap[y][x];
        }
    }
}

bool canAddWall(vector<Point> wallList) {
    Point w1 = wallList[0];
    Point w2 = wallList[1];
    Point w3 = wallList[2];

    if (originMap[w1.y][w1.x] == 0 && originMap[w2.y][w2.x] == 0 && originMap[w3.y][w3.x] == 0)
        return true;
    return false;
}

void addWall(vector<Point> wallList) {
    Point w1 = wallList[0];
    Point w2 = wallList[1];
    Point w3 = wallList[2];

    tempMap[w1.y][w1.x] = 1;
    tempMap[w2.y][w2.x] = 1;
    tempMap[w3.y][w3.x] = 1;
}

void bfs() {
    queue<Point> q;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (tempMap[y][x] == 2) {
                q.emplace(x, y);
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (tempMap[ny][nx] == 0 && !visited[ny][nx]) {
                    q.emplace(nx, ny);
                    visited[ny][nx] = true;
                    tempMap[ny][nx] = 2;
                }
            }
        }
    }
}

int getSafeArea() {
    int count = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (tempMap[y][x] == 0) {
                count++;
            }
        }
    }
    return count;
}

void resetVisited() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            visited[y][x] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    getMap(); //입력 받음

    vector<vector<Point>> w = getWall();

    int safeArea = 0;
    for (int i = 0; i < (int) w.size(); i++) {
        if (!canAddWall(w[i])) {
            continue;
        }
        copyMap();
        addWall(w[i]);
        bfs();
        int tempSafeArea = getSafeArea();
        if (tempSafeArea > safeArea) {
            safeArea = tempSafeArea;
        }
        resetVisited();
    }

    cout << safeArea;

    return 0;
}
// vector size가 원래는 unsigned long type임
// 그대로 백준 돌리면, 컴파일 에러가 발생하기 떄문에
// 명시적으로 (int)로 캐스팅을 해줘야 한다

// #include <algorithm> 신경쓰기 =