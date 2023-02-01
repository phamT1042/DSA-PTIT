#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
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
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') cout << s[i];
        }
        cout << endl;
    }
    return 0;
}