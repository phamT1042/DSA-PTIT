#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int l, n, m; cin >> l >> n >> m;
        string s1, s2, s3; cin >> s1 >> s2 >> s3;
        s1 = "0" + s1;
        s2 = "0" + s2;
        s3 = "0" + s3;
        int dp[l + 1][n + 1][m + 1];
        for (int i = 0; i <= l; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= m; k++) {
                    if (i == 0 || j == 0 || k == 0) {
                        dp[i][j][k] = 0;
                    }
                    else if (s1[i] == s2[j] && s2[j] == s3[k]) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    }
                    else {
                        dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                    }
                }
            }
        }
        cout << dp[l][n][m] << endl;
    }
}