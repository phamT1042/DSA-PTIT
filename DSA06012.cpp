#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, i; cin >> n >> k;
		int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n);
        i = n - 1;
        while (k--) cout << a[i--] << ' ';
        cout << endl;
	}
	return 0;
}