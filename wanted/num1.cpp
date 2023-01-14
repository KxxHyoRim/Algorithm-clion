#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, left = 0, right = 0, max_enlightenment = 0;
    cin >> n;
    vector<int> direction(n);


    cin >> direction[0];

    for (int i = 1; i < n; i++) {
        cin >> direction[i];
        if (direction[i] == direction[i - 1]) {
            if (direction[i] == 1) {
                left++;
                if (i == 1) left++;
            } else {
                right++;
                if (i == 1) right++;
            }
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

    max_enlightenment = max(left, right);
    cout << max_enlightenment << endl;

    return 0;
}
