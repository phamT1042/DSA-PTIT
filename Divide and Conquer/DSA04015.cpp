#include<bits/stdc++.h>
using namespace std;
int binarySearch (vector<long long> a, int l, int r, long long x) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return -1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; long long x, y; cin >> n >> x;
        vector<long long> a;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            cin >> y;
            if (y == x) pos = i + 1;
            else a.push_back(y);
        }
        if (pos) cout << pos;
        else {
            a.push_back(x);
            sort(a.begin(), a.end());
            int pos = binarySearch (a, 0, n, x);
            if (!pos) cout << -1;
            else cout << pos;
        }
        cout << '\n';
    }
}