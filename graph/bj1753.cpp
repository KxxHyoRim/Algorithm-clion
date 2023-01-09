#include <iostream>
#include <queue>
#include <climits>
#include <map>

#define INF INT_MAX

using namespace std;

int V, E, s, u, v, w;
vector<map<int, int>> weight;
vector<bool> visited;
vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> s;
    weight.resize(E + 1);
    visited.resize(V + 1);
    result.resize(V + 1);

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        weight[u].emplace(v, w);
    }

    for (int i = 0; i <= V; i++) { result[i] = INF; }
    result[s] = 0;

    for (int i = 1; i <= V; i++) {

        // 1. s를 정함
        int minDist = INF;
        for (int j = 1; j <= V; j++) {
            if (visited[j]) continue;
            if (result[j] < minDist) {
                minDist = result[j];
                s = j;
            }
        }

        // s와 인접한 node queue 추가
        for (auto iter: weight[s]) {
            int ns = iter.first;
            result[ns] = min(result[ns], result[s] + weight[s].find(ns)->second);
        }

        visited[s] = true;
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
