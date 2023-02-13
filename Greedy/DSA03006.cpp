#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, flag = 1; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        int l = 0, r = n - 1, m = (l + r) / 2;
        while (l < r) {
            while (a[l] < a[m]) l++;
            while (a[r] > a[m]) r--;
            if (l < r) swap(a[l++], a[r--]);
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                flag = 0;
                break;
            }
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}