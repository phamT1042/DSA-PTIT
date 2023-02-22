#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.length();
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
        int lengthMax = 1;
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                if (length == 2 && s[i] == s[j]) 
                    dp[i][j] = 1;
                else 
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                if (dp[i][j]) lengthMax = max(lengthMax, length); 
            }
        }
        cout << lengthMax << endl;
    } 
}