#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, v, i, j; cin >> n >> v;
        int a[n + 1], c[n + 1], dp[n + 1][v + 1]; //Giá trị lớn nhất túi khi 
                                    //chọn trong i đồ vật từ 1 đến i với thể tích tối đa j
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= v; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i - 1][j]; //chưa chọn caí túi thứ i
                    if (j >= a[i]) { //nếu cái túi thứ i chọn được
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + c[i]);
                    }
                }
            }
        }
        cout << dp[n][v] << endl; 
    }
}