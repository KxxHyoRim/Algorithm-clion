#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
    int totalN = (int) nums.size();
    int chooseN = totalN / 2;
    set<int> distinct;
    for (int &num: nums) {
        distinct.emplace(num);
    }
    return (distinct.size() > chooseN) ? (int) chooseN : (int) distinct.size();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> num1 = {3, 1, 2, 3};
    vector<int> num2 = {3, 3, 3, 2, 2, 4};
    vector<int> num3 = {3, 3, 3, 2, 2, 2,};

    cout << solution(num3);

    return 0;
}
