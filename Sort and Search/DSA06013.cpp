#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
        int a[n];
        int cnt = 0;
        for (int &y : a) {
            cin >> y;
            if (y == x) cnt++;
        }
        if (cnt) cout << cnt;
        else cout << -1;
        cout << '\n';
	}
	return 0;
}