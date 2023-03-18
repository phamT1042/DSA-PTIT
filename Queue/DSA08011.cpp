#include <bits/stdc++.h>
using namespace std;
int solve (string s, string t, set<string> a) {
    queue<pair<string, int>> q;
    q.push({s, 1});
    int n = s.length();
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        string tmp = it.first;
        if (tmp == t) return it.second;
        for (int i = 0; i < n; i++) {
            char save = tmp[i];
            for (int j = 'A'; j <= 'Z'; j++) {
                tmp[i] = j;
                if (tmp == t) return it.second + 1;
                if (a.find(tmp) != a.end()) {
                    a.erase(tmp);
                    q.push({tmp, it.second + 1});
                }
            }
            tmp[i] = save;
        }
    }
    return 0;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int n; string s, t;
        cin >> n >> s >> t;
        set<string> a;
        while (n--) {
            string x; cin >> x;
            if (x != s) a.insert(x);
        }
        if (s == t || a.find(t) == a.end()) cout << 0;
        else cout << solve(s, t, a);
        cout << endl;
    }
    return 0;
}