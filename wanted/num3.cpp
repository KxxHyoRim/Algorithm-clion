#include <iostream>

using namespace std;


const int MAX_N = 10001;
const int MAX_M = 10001;
const int MAX_C = 17;

int n, m, c;
int w[MAX_C][MAX_C];
int a[MAX_N], b[MAX_M];
int dp[MAX_N][MAX_M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + w[a[i]][b[j]]);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
