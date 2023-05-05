#include<bits/stdc++.h>
using namespace std;
void preOrder (int a[], int l, int r) {
    if (l <= r) {
        preOrder(a, l, (l + r) / 2 - 1);
        preOrder(a, (l + r) / 2 + 1, r);
        cout << a[(l + r) / 2] << ' ';
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n);
        preOrder(a, 0, n - 1);
        cout << '\n';
    }
}