#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> v;

void dfs(int cnt) {

    // 수열 다 찼을 때
    if (v.size() == k) {
        for (int i = 0; i < k; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = n; i > 0; i--) {
        v.emplace_back(i);
        dfs(cnt + 1);
        v.pop_back();
    }

}


int main() {
    cin >> n >> k;
    dfs(0);
    return 0;
}