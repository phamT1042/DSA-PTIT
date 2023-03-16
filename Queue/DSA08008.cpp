#include<bits/stdc++.h>
using namespace std;
bool check (string s, int n) {
    long long tmp = 0;
    for (int i = 0; i < s.length(); i++) {
        tmp = tmp * 10 + s[i] - '0';
        tmp %= n;
    }
    return tmp == 0;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        queue<string> q;
        q.push("1");
        while (1) {
            string s = q.front(); q.pop();
            if (check(s, n)) {
                cout << s << endl;
                break;
            }
            q.push(s + "0");
            q.push(s + "1");
        }
    }
    return 0;
}