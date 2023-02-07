#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
        int a[n], up[n], down[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            up[i] = down[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) up[i] = up[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) down[i] = down[i + 1] + 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, up[i] + down[i] - 1);
        }
        cout << res << endl;
	}
	return 0;
}