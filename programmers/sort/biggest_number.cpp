#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> str;
    string answer = "";

    for (int i = 0; i < numbers.size(); i++) {
        str.emplace_back(to_string(numbers[i]));
    }

    sort(str.begin(), str.end(), cmp);
    for (int i = 0; i < numbers.size(); i++) {
        answer += str[i];
    }
    // 0일경우 예외처리 해주기
    if (answer[0] == '0') answer = "0";

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> input = {3, 30, 34, 5, 9};
    solution(input);

    return 0;
}
