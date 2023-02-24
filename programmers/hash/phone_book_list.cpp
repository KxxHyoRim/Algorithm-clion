#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool bBeginWithA(string a, string b) {
    return b.substr(0, a.length()) == a;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size(); i++) {
        string a = phone_book[i - 1];
        string b = phone_book[i];
        if (a.length() > b.length()) continue;
        if (bBeginWithA(a, b))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v1 = {"12", "123", "1235", "567", "88"};
    vector<string> v2 = {"119", "97674223", "1195524421"};
    cout << solution(v1);

    return 0;
}
