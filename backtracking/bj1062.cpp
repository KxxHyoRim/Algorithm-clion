#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
string temp;
vector<string> word;
vector<bool> alphabet(26);

void dfs(int v) {
    v

    if (k == 0) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (!alphabet[i])
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> k;
    word.resize(n);

    if (k < 5) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> temp;
        word[i] = temp.substr(4, temp.length() - 8);
        cout << word[i] << endl;
    }

    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    k -= 5;

    for (int i = 0; i < 26; i++) {
        if (k > 0 && !alphabet[i]) {
            dfs(i);
        }
    }

    return 0;
}
