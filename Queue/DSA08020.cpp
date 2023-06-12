#include <bits/stdc++.h>
using namespace std;
int sang[10000];
void sangNT() {
    for (int i = 0; i < 10000; i++) sang[i] = 1;
    sang[0] = sang[1] = 0;
    for (int i = 2; i < 100; i++) {
        if (sang[i]) {
            for (int j = i * i; j < 10000; j += i) sang[j] = 0;
        }
    }
}
int solve(string s, string t) {
    queue<pair<string, int>> q;
    unordered_map<string, int> check;
    q.push({s, 0});
    check[s] = 1;
    int j;
    while (!q.empty()) {
        auto tmp = q.front(); q.pop();
        string s1 = tmp.first;
        for (int i = 0; i < 4; i++) {
            if (i == 0) j = 1;
            else j = 0;
            for (j; j < 10; j++) {
                if (s1[i] - '0' != j) {
                    string testStr = s1.substr(0, i) + to_string(j);
                    if (i < 3) testStr += s1.substr(i + 1, 3 - i);
                    if (testStr == t) return tmp.second + 1;
                    else {
                        if (sang[stoi(testStr)] && !check[testStr]) {
                            check[testStr] = 1;
                            q.push({testStr, tmp.second + 1});
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main() {
    sangNT();
    int t; cin >> t;
    while (t--) {
        string s, t; cin >> s >> t;
        if (s == t) cout << 0;
        else cout << solve(s, t);
        cout << "\n";
    }
    return 0;
}
