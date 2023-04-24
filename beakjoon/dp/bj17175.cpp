#include <iostream>

using namespace std;

int dp[51];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1] + 1 /* 자기자신 */ ) % 1000000007;
    }
    cout << dp[n];

    return 0;
}
