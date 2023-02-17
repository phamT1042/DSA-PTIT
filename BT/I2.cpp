#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, s, k; cin >> n >> s >> k;
        int a[n];
        long long pre[n];
        s--;
        cin >> a[0]; pre[0] = a[0];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        int T = -2;
        for (int i = 0; i <= s; i++) {
            if (pre[s] - pre[i] + a[i] <= k) {
                T = i;
                break;
            }
        }
        cout << T + 1 << endl;
    }
}