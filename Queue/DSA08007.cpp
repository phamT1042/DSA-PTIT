#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string n; cin >> n;
        queue<string> q;
        q.push("1");
        int cnt = 0;
        while (1) {
            string s = q.front(); q.pop();
            if (s.length() == n.length() && s <= n || s.length() < n.length()) cnt++;
            else break;
            q.push(s + "0");
            q.push(s + "1");
        }
        cout << cnt << endl;
    }
    return 0;
}