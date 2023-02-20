#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, s, i, j; cin >> n >> s;
        int a[n], dp[s + 1];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i <= s; i++) dp[i] = 0;
        dp[0] = 1;
        for (i = 0; i < n; i++) {
            for (j = s; j >= a[i]; j--) {
                if (dp[j - a[i]]) dp[j] = 1;
            }
        }
        if (dp[s]) cout << "YES\n";
        else cout << "NO\n";
    }
}