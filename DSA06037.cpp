#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        int a[n], Max[n], Min[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            Max[i] = a[i];
            Min[i] = a[i];
        }
        for (int i = 1; i < n; i++) {
            Max[i] = max(a[i], Max[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            Min[i] = min(a[i], Min[i + 1]);
        }
        int k = 0;
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            if (Max[i] <= Min[i + 1]) {
                k++;
                res.push_back(i + 1);
            }
        }
        if (k) {
            cout << k << endl;
            for (int x : res) cout << x << ' ';
            cout << endl;
        }
        else {
            cout << "0\n\n";
        }
	}
	return 0;
}