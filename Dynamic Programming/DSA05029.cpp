#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s; 
        if (s[0] == '0') cout << "0\n"; //số 0 đứng đầu thì không thể giải mã
        else {
            int n = s.length();
            int dp[n + 1];
            dp[0] = dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                dp[i] = 0;
                if (s[i - 1] > '0') dp[i] = dp[i - 1]; //Nếu chữ số ở vị trí i - 1 khác 0, 
                    //nó có thể đứng riêng rẽ ghép với các số ở vị trí i - 2 đổ về trước
                if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7') dp[i] += dp[i - 2];
                //Nếu chữ số ở vị trí i - 2 hợp với vị trí i - 1 có thể tạo 1 số >= 10 && <= 27
                //ta có thể ghép 2 số đó với nhau rồi kết hợp các số ở vị trí i - 3 đổ về trước
            }
            cout << dp[n] << endl;
        }
    }
    return 0;
}