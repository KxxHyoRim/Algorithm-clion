#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> acc;

    for (int i = 0; i < clothes.size(); i++) {
        acc[clothes[i][1]] += 1;
    }

    int answer = 1;
    for (auto i = acc.begin(); i != acc.end(); i++) {
        int value = i->second;
        answer *= (value + 1);
    }

    return answer - 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num.txt", "r", stdin);

    return 0;
}
