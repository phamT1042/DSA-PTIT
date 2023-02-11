#include<bits/stdc++.h>
using namespace std;
string res;
void Try (int k, string s) {
    if (k == 0) return;
    for (int i = 0; i < s.length() - 1; i++) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                res = max(res, s);
                Try(k - 1, s);
                swap(s[i], s[j]);
            }
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int k; string s;
        cin >> k >> s;
        res = s;
        Try(k, s);
        cout << res << endl;
    }
}