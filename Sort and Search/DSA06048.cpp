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
        int n, k = 0; cin >> n;
        long long a[n], check[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            check[i] = a[i];
        }
        sort(check, check + n);
        int pos = binarySearch(0, n - 1, a[0], check);
        cout << (n - pos) % n << endl;
	} 
	return 0;
}