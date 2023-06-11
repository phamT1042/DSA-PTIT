#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n, x; cin >> n;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> x;
            cnt[x]++;
        }
        int res = 0;
        for (auto it : cnt) {
            if (it.second > n / 2) {
                res = it.first;
                break;
            }
        }
        if (!res) cout << "NO\n";
        else cout << res << endl;
	}
	return 0;
}