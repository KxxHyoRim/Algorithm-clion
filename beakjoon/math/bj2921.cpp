#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum = 0;
    cin >> n;

    for (int i = 0; i <= n; i++)
        for (int j = i; j <= n; j++)
            sum += (i + j);

    cout << sum;
    return 0;
}
