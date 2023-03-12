#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	long long dp[b + 1];
	for (int i = 0; i < b + 1; i++) dp[i] = 0;
	for (int i = 1; i <= b; i++) {
		for (int j = 2;; j++) {
			if (i * j <= b) dp[i * j] += i; 
			else break;
		}
	}
	int res = 0;
	for (int i = a; i <= b; i++) {
		if (dp[i] > i) res++;
	}
	cout << res;
	return 0;
}


