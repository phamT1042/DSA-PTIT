#include<bits/stdc++.h>
using namespace std;
long long dp[101][50001];
int main() {
    long long MOD = 1e9 + 7;
    //Số số có i chữ số có tổng các chữ số là j
    //=> Các số có i chữ số có tổng j chính là tổng số các số có i - 1 chữ số có
    //tổng các chữ số là 1, 2,...,j. Chú ý rằng nếu j > i * 9 thì dp[i][j] = 0
    //VD như i = 2, j = 19, không có số nào thoả mãn.
    for (int j = 1; j <= 9; j++) {
        dp[1][j] = 1;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int z = j; z <= 50000; z++) {
                dp[i][z] += dp[i - 1][z - j];
                dp[i][z] %= MOD;
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n == 1 && k == 0) cout << "1\n";
        else
            cout << dp[n][k] << "\n";
    }
    return 0;
}