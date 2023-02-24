#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string name, state;
    set<string> s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name >> state;
        if (state == "enter")s.insert(name);
        else s.erase(name);
    }

    vector<string> v(s.begin(), s.end());
    sort(v.rbegin(), v.rend());

    for (const auto &i: v) {
        cout << i << "\n";
    }

    return 0;
}
