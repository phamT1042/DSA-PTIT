#include<bits/stdc++.h>
using namespace std;
string xoaNgoac (string s) {
    stack<char> t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') t.push(i);
        else if (s[i] == ')') {
            int m = t.top(); t.pop();
            if (m - 1 >= 0) {
                if (s[m - 1] == '-') {
                    for (int j = m + 1; j < i; j++) {
                        if (s[j] == '-') s[j] = '+';
                        else if (s[j] == '+') s[j] = '-';
                    }
                }
            }
        }
    }
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '(' && s[i] != ')') tmp += s[i];
    }
    return tmp;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        s1 = xoaNgoac(s1);
        s2 = xoaNgoac(s2);
        if (s1 == s2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}