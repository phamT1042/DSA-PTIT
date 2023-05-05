#include<bits/stdc++.h>
using namespace std;
int used[20], k, s, a[20], n, flag; 
void Try (int i, int sum, int cntTapCon) {
    if (cntTapCon == k) {
        flag = 1;
        return;
    }
    for (int j = i; j < n; j++) {
        if (!used[j] && sum + a[j] <= s) {
            used[j] = 1;
            if (sum + a[j] == s && !flag) Try(0, 0, cntTapCon + 1);
            else if (!flag) Try(j + 1, sum + a[j], cntTapCon);
            used[j] = 0;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        s = flag = 0;
        for (int i = 0; i < n; i++) {
            used[i] = 0;
            cin >> a[i];
            s += a[i];
        }
        if (s % k != 0) cout << '0';
        else {
            s /= k;
            Try(0, 0, 0);
            cout << flag;
        }
        cout << '\n';
    }
    return 0;
}