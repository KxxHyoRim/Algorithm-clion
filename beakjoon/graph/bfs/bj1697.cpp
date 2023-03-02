#include <iostream>
#include <queue>
#include <climits>

using namespace std;

const int LIMIT = 100000;
int n, k, result = INT_MAX;
bool visited[LIMIT + 1];
int dist[LIMIT + 1];

void bfs(int curr) {
    visited[curr] = true;
    dist[curr] = 0;

    queue<int> q;
    q.emplace(curr);

    while (!q.empty()) {
        curr = q.front();
        q.pop();
        if (curr == k) {
            if (dist[curr] < result) { result = dist[curr]; }
        }
        int candidate[3] = {curr + 1, curr - 1, curr * 2};
        for (int nx: candidate) {
            if (nx >= 0 && nx <= LIMIT && !visited[nx]) {
                q.emplace(nx);
                visited[nx] = true;
                dist[nx] = (dist[nx] == 0 && nx != n) ? dist[curr] + 1 : min(dist[nx], dist[curr] + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    bfs(n);
    cout << dist[k];

    return 0;
}
