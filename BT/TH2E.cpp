#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int a[n][m], cot[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (i == 0) cot[i][j] = a[i][j];
				else {
					if (a[i][j]) cot[i][j] = cot[i - 1][j] + 1;
					else cot[i][j] = 0;
				}
			}
		}
		stack<int> pos;
		int resA = 0, resB = INT_MAX, maxS = 0, dai, rong;
		for (int i = 0; i < n; i++) {
			pos.push(0);
			for (int j = 1; j < m; j++) {
				while (cot[i][j] < cot[i][pos.top()]) {
					int idx = pos.top(); pos.pop();
					if (pos.empty()) {
						dai = max(j, cot[i][idx]);
						rong = min(j, cot[i][idx]);
						if (dai * rong > maxS) {
							maxS = dai * rong;
							resB = dai;
							resA = rong;
						}
						else if (dai * rong == maxS) {
							if (resB - resA > dai - rong) {
								resB = dai;
								resA = rong;
							}
						}
						break;
					}
					else {
						dai = max(cot[i][idx], j - pos.top() - 1);
						rong = min(cot[i][idx], j - pos.top() - 1);
						if (dai * rong > maxS) {
							maxS = dai * rong;
							resB = dai;
							resA = rong;
						}
						else if (dai * rong == maxS) {
							if (resB - resA > dai - rong) {
								resB = dai;
								resA = rong;
							}
						}
					}
				}
				pos.push(j);
			}
			while (pos.size()) {
				int idx = pos.top(); pos.pop();
				if (pos.empty()) {
					dai = max(m, cot[i][idx]);
					rong = min(m, cot[i][idx]);
					if (dai * rong > maxS) {
						maxS = dai * rong;
						resB = dai;
						resA = rong;
					}
					else if (dai * rong == maxS) {
						if (resB - resA > dai - rong) {
							resB = dai;
							resA = rong;
						}
					}
					break;
				}
				else {
					dai = max(cot[i][idx], m - pos.top() - 1);
					rong = min(cot[i][idx], m - pos.top() - 1);
					if (dai * rong > maxS) {
						maxS = dai * rong;
						resB = dai;
						resA = rong;
					}
					else if (dai * rong == maxS) {
						if (resB - resA > dai - rong) {
							resB = dai;
							resA = rong;
						}
					}
				}
			}
		}
		cout << resA << ' ' << resB << '\n';
	}
	return 0;
}
