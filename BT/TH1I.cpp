#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	int v[n + 1], w[n + 1], dp[n + 1][m + 1];
	for (int i = 1; i <= n; i++) {
		cin >> v[i] >> w[i];
	}
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int j = 0; j <= m; j++) dp[0][j] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= v[i]) {
				dp[i][j] = max (dp[i][j], dp[i - 1][j - v[i]] + w[i]);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}


