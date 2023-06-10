#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n);
        int l = 0, r = n - 1, i = 0;
        while (l <= r) {
            if (!i) {
                cout << a[r--] << ' '; i = 1; 
            }
            else {
                cout << a[l++] << ' '; i = 0;
            }
        }
        cout << '\n';
    }
}