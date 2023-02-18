#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n);
        int l = n / 2 - 1, r = n - 1, res = n;
        while (l >= 0 && r > n / 2) {
            if (a[r] >= a[l] * 2) {
                res--;
                r--; l--;
            }
            else l--;
        }
        cout << res << endl;
    }
}