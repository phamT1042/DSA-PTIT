#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
	    int n; long long k; cin >> n >> k;
		map<long long, long long> dem;
		set<long long> sol;
		for (int i = 0; i < n; i++) {
		    long long x; cin >> x;
		    dem[x]++;
		    sol.insert(x);
		}
		long long res = 0;
		for (long long x : sol) {
			if (x != k - x) {
				res += dem[x] * dem[k - x];
				dem[x] = dem[k - x] = 0;
			} else res += dem[x] * (dem[x] - 1) / 2;
		}
		cout << res << endl;
	}
	return 0;
}