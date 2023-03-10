#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        stack<string> q;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                string tmp = ""; tmp += s[i];
                q.push(tmp);
            }
            else {
                string day1 = q.top(); q.pop();
                string day2 = q.top(); q.pop();
                q.push("(" + day2 + s[i] + day1 + ")");
            }
        }
        cout << q.top() << endl;
    }
    return 0;
}