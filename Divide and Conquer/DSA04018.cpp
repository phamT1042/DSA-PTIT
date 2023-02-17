#include<bits/stdc++.h>
using namespace std;
int found;
void binarySearch (int a[], int l, int r) {
    if (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == 1) binarySearch(a, l, m - 1);
        if (a[m] <= 0) {
            found = m;
            if (m + 1 <= r)
                binarySearch(a, m + 1, r);
        }
    }
    return;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        found = -1;
        binarySearch(a, 0, n - 1);
        cout << found + 1 << endl;
    }
}