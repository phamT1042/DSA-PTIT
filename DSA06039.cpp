#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n, k; cin >> n;
        int a[n]; map<int, int> cnt;
        for (int &x : a) {
            cin >> x;
            cnt[x]++;
        }
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] > 1) {
                flag = 1;
                cout << a[i] << endl;
                break;
            }
        }
        if (!flag) cout << "NO\n";
	}
	return 0;
}