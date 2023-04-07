#include<bits/stdc++.h>
using namespace std;
bool check (string s) {
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') cnt++;
    }
    return cnt > n / 2;
}
int main() {
    queue<string> q;
    vector<string> res;
    q.push("1");
    q.push("2");
    while (res.size() < 1000) {
        string s = q.front(); q.pop();
        if (check(s)) res.push_back(s);
        for (int i = 0; i <= 2; i++) {
            q.push(s + to_string(i));
        }
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cout << res[i] << ' ';
        cout << endl;
    }
}
