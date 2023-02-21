#include<bits/stdc++.h>
using namespace std;
int main() {
    int c, n; cin >> c >> n;
    int w[n + 1], dp[n + 1][c + 1]; //Khối lượng bò lớn nhất nếu chọn ra trong 1,2,...,i con bò 
                                    //với trọng lượng tối đa j
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j];
                if (j >= w[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
                }
            }
        }
    }
    cout << dp[n][c];
}