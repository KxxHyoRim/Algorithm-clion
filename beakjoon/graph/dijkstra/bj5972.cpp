#include <iostream>
#include <climits>
#include <queue>

using namespace std;
vector<pair<int, int >> graph[50001];
int dist[50001];

void initDist() {
    for (int i = 0; i < 50000; i++)
        dist[i] = INT_MAX;
}

void dijkstra() {
    priority_queue<pair<int, int> > pq; // <여물, 현재노드>
    pq.emplace(0, 0); // 시작위치 0
    dist[0] = 0;
    while (!pq.empty()) {
        int curr_cost = -pq.top().first; // 현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();
        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (dist[now] < curr_cost) continue;
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = curr_cost + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < dist[graph[now][i].first]) {
                dist[graph[now][i].first] = cost;
                pq.emplace(-cost, graph[now][i].first);
            }
        }
    }
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--; // 시작 idx 0으로 가정
        graph[a].emplace_back(b, c); // a -> b : c여물
        graph[b].emplace_back(a, c); // b -> a : c여물
    }
    initDist();
    dijkstra();

    cout << dist[n - 1];
    return 0;
}
