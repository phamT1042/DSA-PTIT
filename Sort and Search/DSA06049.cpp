#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for (int &x : a) cin >> x;
        long long res = 0;
        sort(a, a + n);
        for (int i = 0; i < n - 1; i++) {
            res += lower_bound(a + i + 1, a + n, k + a[i]) - a - i - 1;
        }
        cout << res << endl;
	} 
	return 0;
}