#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        int a[n], pre[n];
        memset(pre, 0, sizeof(pre));
        cin >> a[0];
        pre[0] = a[0];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        int flag = 0;
        for (int i = 1; i < n - 1; i++) {
            if (pre[i - 1] == pre[n - 1] - pre[i]) {
                flag = 1;
                cout << i + 1 << endl;
                break;
            }
        }
        if (!flag) cout << "-1\n";
	}
	return 0;
}