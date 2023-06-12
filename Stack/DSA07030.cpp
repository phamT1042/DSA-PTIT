#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int a[n][m], cot[n][m];
		for (int i = 0; i < m; i++) {
			cin >> a[0][i];
			cot[0][i] = a[0][i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j]) cot[i][j] = cot[i - 1][j] + 1;
				else cot[i][j] = 0;
			}
		}
		int Smax = INT_MIN, idx;
		for (int i = 0; i < n; i++) {
			stack<int> st;
			st.push(0);
			for (int j = 1; j < m; j++) {
				while (cot[i][j] < cot[i][st.top()]) {
					idx = st.top(); st.pop();
					if (st.empty()) {
						Smax = max(Smax, cot[i][idx] * j); 
						break;
					}
					else Smax = max(Smax, cot[i][idx] * (j - st.top() - 1));
				}
				st.push(j);
			}
			while (st.size()) {
				idx = st.top(); st.pop();
				if (st.empty()) Smax = max(Smax, cot[i][idx] * m);
				else Smax = max(Smax, cot[i][idx] * (m - st.top() - 1));
			}
		}
		cout << Smax << '\n';
	}
	return 0;
}