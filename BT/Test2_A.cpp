#include<bits/stdc++.h>
using namespace std;
int n, k, a[30];
set<string> res;
string s; 
void xet() {
	string x = "";
	for (int i = 1; i <= k; i++) {
		x += s[a[i] - 1];
	}
	res.insert(x);
}
void Try (int i) {
	for (int j = a[i - 1] + 1; j <= n; j++) {
		a[i] = j;
		if (i == k) xet();
		else Try(i + 1);
	}
}
int main() {
    int t; cin >> t;
    while (t--) {
		cin >> s >> k;
		n = s.length();
		Try(1);
		for (string x : res) cout << x << '\n';
		res.clear();
    } 
	return 0; 
}