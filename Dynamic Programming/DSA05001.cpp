#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        int n = s1.length(), m = s2.length();
        s1 = "0" + s1;
        s2 = "0" + s2;
        int l[n + 1][m + 1]; //Độ dài xâu con chung dài nhất có được bằng cách
                             //lấy i kí tự đầu xâu S1 và j kí tự đầu xâu S2
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) l[i][j] = 0;
                else if (s1[i] == s2[j]) l[i][j] = l[i - 1][j - 1] + 1;
                else l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
        cout << l[n][m] << endl;
    }
}