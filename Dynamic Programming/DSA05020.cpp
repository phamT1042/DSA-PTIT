#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int a[n][m], dp[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                dp[i][j] = a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0 && j > 0) dp[i][j] += dp[i][j - 1];
                else if (i > 0 && j == 0) dp[i][j] += dp[i - 1][j];
                else {
                    dp[i][j] = min(dp[i][j] + dp[i - 1][j], min(dp[i][j] + dp[i][j - 1], dp[i][j] + dp[i - 1][j - 1]));
                } 
            }
        }
        cout << dp[n - 1][m - 1] << endl;
    } 
}