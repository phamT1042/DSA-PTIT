#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        long long n, k; cin >> n >> k;
        long long a[n];
        for (long long &x : a) cin >> x;
        long long res = 0;
        sort(a, a + n);
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > k) break;
            for (int j = i + 1; j < n; j++) {
                auto it = upper_bound(a + j + 1, a + n, k - a[i] - a[j] - 1);
                int pos = it - a;
                if (pos > j) res += pos - j - 1;
                else break;
            }
        }
        cout << res << endl;
    }
	return 0;
}