#include <bits/stdc++.h>
using namespace std;
int n; 
long long c[16][16], cmin = LONG_LONG_MAX, fopt = LONG_LONG_MAX, f = 0;
vector<int> res;
int sh[16], used[16];
void Try (int i) {
	if (f + cmin * (n - i + 1) >= fopt) return;
	for (int j = 2; j <= n; j++) {
		if (!used[j]) {
			sh[i] = j;
			used[j] = 1;
			f += c[sh[i - 1]][j];
			if (i == n) {
				if (f + c[sh[n]][1] < fopt) {
					fopt = f + c[sh[n]][1];
					res.clear();
					for (int k = 1; k <= n; k++) res.push_back(sh[k]);
				}
			}
			else Try (i + 1);
			used[j] = 0;
			f -= c[sh[i - 1]][j];
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			if (c[i][j] != 0 && c[i][j] < cmin) cmin = c[i][j];
		}
	}
	sh[1] = 1;
	Try(2);
	cout << "(";
	for (int x : res) cout << x << ",";
	cout << "1)\n" << fopt;
	return 0;
}
