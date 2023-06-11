#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n);
        int flag = 0;
        for (int i = 0; i < n - 2; i++) {
            if (a[i] > k) break;
            for (int j = i + 1; j < n - 1; j++) {
                if (a[i] + a[j] > k) break;
                if (binary_search(a + j + 1, a + n, k - a[i] - a[j])) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}