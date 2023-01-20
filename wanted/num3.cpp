#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 10001;
const int MAX_C = 17;

int n, m, c;
int w[MAX_C][MAX_C];
int a[MAX_N], b[MAX_N];
vector<bool> shakeA;
vector<bool> shakeB;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> c;

    shakeA.resize(n, true);
    shakeB.resize(m, true);

    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> w[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int result = 0;

    int k = min(n, m);
    if (k == n) { // a대학의 수가 더 작음 -> b에서 조합돌리기
        for (int i = 0; i < (int) shakeB.size() - k; i++) // 뒤에 false가 n-r개 채워지고 뒤에 true 가 r개 채워진다.
            shakeB[i] = false;

        do {
            int satisfy = 0;
            int idx = 0;

            for (int i = 0; i < (int) shakeB.size(); ++i) {
                if (shakeB[i]) {
                    // cout << i << " ";
                    int personality1 = b[i];
                    int personality2 = a[idx];
                    satisfy += w[personality1][personality2];
                    idx++;
                }
            }

            // cout << satisfy << endl;

            if (satisfy > result)
                result = satisfy;

        } while (next_permutation(shakeB.begin(), shakeB.end()));
    } else { // b대학생 수가 더 적음 -> a에서 조합 돌리기
        for (int i = 0; i < (int) shakeA.size() - k; i++) // 뒤에 false가 n-r개 채워지고 뒤에 true 가 r개 채워진다.
            shakeA[i] = false;

        do {
            int satisfy = 0;
            int idx = 0;

            for (int i = 0; i < (int) shakeA.size(); ++i) {
                if (shakeA[i]) {
                    cout << i << " ";
                    int personality1 = a[i];
                    int personality2 = b[idx];
                    satisfy += w[personality1][personality2];
                    idx++;
                }
            }

            cout << satisfy << endl;

            if (satisfy > result)
                result = satisfy;

        } while (next_permutation(shakeA.begin(), shakeA.end()));
    }


    cout << result;
    return 0;
}
