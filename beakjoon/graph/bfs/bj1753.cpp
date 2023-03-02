#include <iostream>
#include <queue>
#include <climits>

#define INF INT_MAX

using namespace std;

int V, E, s, u, v, w;
vector<vector<pair<int, int>>> graph;
int result[20001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> s;
    graph.resize(V + 1);

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); // u에서 v까지 하는데 w만큼
    }

    for (int i = 1; i <= V; i++) { result[i] = INF; }
    result[s] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        w = -pq.top().first;
        s = pq.top().second;
        pq.pop();

        if (result[s] < w) continue;   // ? 원래 봤던건 이미 안보겠다..

        for (int i = 0; i < graph[s].size(); i++) {
            int nw = graph[s][i].second;
            int ns = graph[s][i].first;
            int newPath = result[s] + nw;
            if (newPath < result[ns]) {
                result[ns] = newPath;
                pq.emplace(-newPath, ns);
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        int tmp = result[i];
        if (tmp == INF)
            cout << "INF" << "\n";
        else
            cout << result[i] << "\n";
    }

    return 0;
}
