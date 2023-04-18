#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        int n = s1.length(), m = s2.length();
        s1 = "0" + s1;
        s2 = "0" + s2;
        int dp[n + 1][m + 1]; 
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                //2 str rỗng thì không làm gì
                if (i == 0 && j == 0) dp[i][j] = 0;
                //str1 rỗng thì insert cho đến khi giống str2
                else if (i == 0) dp[i][j] = j;
                //str2 rỗng thì delete str1 cho đến khi giống str2
                else if (j == 0) dp[i][j] = i;
                //nếu 2 kí tự cuối của 2 string giống nhau, bỏ qua chúng và đếm cho string còn lại của 2 string
                else if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
                //Nếu 2 kí tự cuối không giống nhau, xét 3 thao tác trên ký tự cuối cùng của str1, lấy thao tác tối thiểu:
                //insert: dp[i - 1][j]
                //delete: dp[i][j - 1]
                //replace: dp[i - 1][j - 1]
                else dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
        cout << dp[n][m] << '\n';
    }
}