#include <bits/stdc++.h>
using namespace std;
int binarySearch (int l, int r, long long x, long long a[]) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        else if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return -1;
}
int main() {
	int t; cin >> t;
	while (t--) {
        int n, flag = 0; cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) {
            long long x; cin >> x;
            a[i] = x * x;
        }
        sort(a, a + n);
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                long long c = a[i] + a[j];
                int pos = binarySearch(j + 1, n - 1, c, a);
                if (pos != -1) {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag) cout << "NO\n";
        else cout << "YES\n";
	} 
	return 0;
}