#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, leftN = 0, rightN = 0, max_enlightenment = 0;
bool visited[100001];
vector<int> direction;

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
    for (int i = 1; i < n - 1; i++) {
        int l = direction[i - 1];
        int c = direction[i];
        int r = direction[i + 1];

        if (l != c && c != r) {
            // do nothing
        } else if (c == 1) leftN++;
        else rightN++;
    }

    // 첫번째
    if (direction[0] == direction[1]) {
        if (direction[0] == 1) leftN++;
        else rightN++;
    }

    if (direction[n - 1] == direction[n - 2]) {
        if (direction[n - 1] == 1) leftN++;
        else rightN++;
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
