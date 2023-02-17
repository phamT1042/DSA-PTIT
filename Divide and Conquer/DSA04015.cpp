#include<bits/stdc++.h>
using namespace std;
int found;
int binarySearch (long long a[], int l, int r, long long x) {
    if (l <= r) {
        int m = (l + r) / 2;
        if (a[m] > x) return binarySearch(a, l, m - 1, x);
        if (a[m] <= x) {
            found = m;
            if (a[m] == x) return m;
            if (m + 1 <= r)
                return binarySearch(a, m + 1, r, x);
        }
    }
    return found;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; long long x; cin >> n >> x;
        long long a[n];
        found = -1;
        for (long long &y : a) cin >> y;
        int endFind = binarySearch(a, 0, n - 1, x);
        if (endFind == -1) cout << "-1";
        else cout << endFind + 1;
        cout << endl;
    }
}