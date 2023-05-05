#include<bits/stdc++.h>
using namespace std;
int cnt;
void preOrder (int a[], int l, int r) {
    if (l < r) {
        preOrder(a, l, (l + r) / 2 - 1);
        preOrder(a, (l + r) / 2 + 1, r);
    }
    else if (l == r) cnt++;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cnt = 0;
        int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n);
        preOrder(a, 0, n - 1);
        cout << cnt << '\n';
    }
}