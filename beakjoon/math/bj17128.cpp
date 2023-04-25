#include <iostream>
#include <vector>

using namespace std;

int n, q, tmp;
vector<int> cow;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cow.emplace_back(tmp);
    }

    // 4마리씩 곱한 결과 저장
    int num = (int) cow.size();
    vector<int> cow_four;

    for (int i = 0; i < num; i++) {
        int mul = cow[i] * cow[(i + 1) % num] * cow[(i + 2) % num] * cow[(i + 3) % num];
        cow_four.emplace_back(mul);
    }

    int origin_s = 0;
    for (int i = 0; i < num; i++) {
        origin_s += cow_four[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> tmp;
        tmp--; // idx 가 1부터 시작

        int set1 = (tmp - 3) < 0 ? tmp - 3 + num : tmp - 3;
        int set2 = (tmp - 2) < 0 ? tmp - 2 + num : tmp - 2;
        int set3 = (tmp - 1) < 0 ? tmp - 1 + num : tmp - 1;
        int set4 = tmp;

        int sub = cow_four[set1] + cow_four[set2] + cow_four[set3] + cow_four[set4];
        origin_s -= sub;

        cow_four[set1] *= -1;
        cow_four[set2] *= -1;
        cow_four[set3] *= -1;
        cow_four[set4] *= -1;

        origin_s += (-1 * sub);
        cout << origin_s << "\n";
    }
    return 0;
}
