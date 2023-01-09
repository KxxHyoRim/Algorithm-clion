#include <iostream>
#include <queue>

using namespace std;

int n, m, v, node1, node2;
int graph[1001][1001];
bool visited[1001];

void dfs(int x);

void bfs(int x);

void resetVisited();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> v;
    for (int i = 0; i < m; ++i) {
        cin >> node1 >> node2;
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }

    dfs(v);
    cout << "\n";
    resetVisited();
    bfs(v);


    return 0;
}

void resetVisited() {
    for (bool &i: visited) {
        i = false;
    }
}


void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i <= n; i++) {
        if (graph[x][i] == 1 && !visited[i])
            dfs(i);
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int i = 0; i <= n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}