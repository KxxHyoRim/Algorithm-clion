#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {

    vector<int> num_list;
    vector<char> num;

    int n = numbers.length();
    for (int i = 0; i < n; i++) {
        num.push_back(numbers[i]);
    }

    sort(num.begin(), num.end());

    do {
        string temp = "";
        for (int i = 0; i < num.size(); i++) {
            temp += num[i];
            num_list.push_back(stoi(temp));
        }
    } while (next_permutation(num.begin(), num.end()));

    // 아래와 같이 하면 모든 조합을 구할 수 없음
//    for (int i = 1; i < pow(2, n); i++) {
//        int combi = 0b1 * i; // 01 10 11
//        string tmp;
//        for (int j = n - 1; j >= 0; j--) {
//            if (combi & (1 << j)) {
//                tmp += num[j];
//            }
//        }
//        num_list.emplace_back(stoi(tmp));
//    }

    int answer = 0;

    //unique(num_list.begin(), num_list.end());
    sort(num_list.begin(), num_list.end());
    num_list.erase(unique(num_list.begin(), num_list.end()), num_list.end());

    for (int i = 0; i < num_list.size(); i++) {
        if (isPrime(num_list[i])) {
            answer++;
        }
    }

    cout << answer << endl;

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//    solution("17");
    solution("011");

    return 0;
}
