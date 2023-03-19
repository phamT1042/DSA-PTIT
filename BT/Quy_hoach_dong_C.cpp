#include<bits/stdc++.h>
using namespace std;
int main() { 
    string s; cin >> s;
    int dp[s.length()][s.length()];
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (i == j) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    for (int i = s.length() - 2; i >= 0; i--) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] == s[j]) {
                if (j - i == 1) dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        l--; r--;
        if (dp[l][r]) cout << "YES\n";
        else cout << "NO\n";
    }
}
