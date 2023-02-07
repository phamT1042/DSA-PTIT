#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        int a[n], Max[n], Min[n]; //Max[i]: max trong đoạn [a0,..,ai]
                                  //Min[i]; min trong đoạn [ai,..,a(n-1)]
        cin >> a[0];
        Max[0] = a[0];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            Max[i] = max(a[i], Max[i - 1]);
            Min[i] = a[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            Min[i] = min(a[i], Min[i + 1]);
        }
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            if (Max[i] <= Min[i + 1]) {
                res.push_back(i + 1);
            }
        }
        if (res.size() != 0) {
            cout << res.size() << endl;
            for (int x : res) cout << x << ' ';
            cout << endl;
        }
        else {
            cout << "0\n\n";
        }
	}
	return 0;
}