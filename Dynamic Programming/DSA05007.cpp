#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long a[n], dp[n];
        for (long long &x : a) cin >> x;
        dp[0] = a[0]; 
        dp[1] = a[1];
        dp[2] = a[2] + dp[0];
        for (int i = 3; i < n; i++) {
            dp[i] = max(a[i] + dp[i - 3], a[i] + dp[i - 2]);
        }
        cout << *max_element(dp, dp + n) << endl;
    }
}