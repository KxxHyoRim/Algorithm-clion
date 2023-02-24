#include<iostream>
#include <map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> name;
    for (int i = 0; i < completion.size(); i++) {
        name[completion[i]] += 1;
    }

    for (int i = 0; i < participant.size(); i++) {
        name[participant[i]] -= 1;
        if (name[participant[i]] < 0)
            return participant[i];
    }
    return "error";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> p1 = {"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> c1 = {"josipa", "filipa", "marina", "nikola"};


    vector<string> p2 = {"mislav", "stanko", "mislav", "ana"};
    vector<string> c2 = {"stanko", "ana", "mislav"};

    cout << solution(p1, c1);
    return 0;
}
