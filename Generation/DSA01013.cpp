#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) s[i] = '1';
            else s[i] = '0';
        }
        cout << s << endl;
    }
    return 0;
}