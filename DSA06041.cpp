#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        int a[n];
        map<int, int> cnt;
        for (int &x : a) {
            cin >> x;
            cnt[x]++;
        }
        int Max = 1, res = 0;
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