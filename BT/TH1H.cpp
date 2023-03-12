#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	int dp[s.length()];
	for (int i = 0; i < s.length(); i++) dp[i] = 1;
	for (int i = 1; i < s.length(); i++) {
		for (int j = 0; j < i; j++) {
			if (s[i] >= s[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp, dp + s.length());
	return 0;
}
