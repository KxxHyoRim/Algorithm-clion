#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, leftN = 0, rightN = 0, max_enlightenment = 0;
bool visited[100001];
vector<int> direction;


int bfs(int x) { //index
    visited[x] = true;
    int count = 0;

    queue<int> q;
    q.emplace(x);

    while (!q.empty()) {
        count++;
        x = q.front();
        q.pop();
        int nx = x + 1;
        if (nx <= n && !visited[nx]) {
            if (direction[x] == direction[nx]) {
                q.emplace(nx);
                visited[nx] = true;
            }
        }
    }

    if (count == 1)
        return 0;

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    direction.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> direction[i];
    }

    // bfs
    for (int i = 0; i < n; i++) {


        if (direction[i] == 1 && !visited[i]) {
            leftN += bfs(i);
        } else if (direction[i] == 2 && !visited[i]) {
            rightN += bfs(i);
        }
    }

    if (n == 1) {
        cout << 1;
        return 0;
    } else if (n == 2) {
        if (direction[0] != direction[1])
            cout << 1;
        else cout << 2;
        return 0;
    }

    cout << max(leftN, rightN);


    return 0;
}
