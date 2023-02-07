#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
        long long x;
        set<long long> a, b;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            b.insert(x);
        }
        cout << *a.rbegin() * *b.begin() << endl;
	}
	return 0;
}