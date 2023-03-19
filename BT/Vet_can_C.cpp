#include<bits/stdc++.h>
using namespace std;
char a;
int n, sh[17];
vector<string> res;
bool check() {
	int cntX = 0, cntXMax = 0, cntO = 0, cntOMax = 0;
	for (int i = 0; i < n; i++) {
		if (sh[i] == 1) {
			cntX = 0;
			while (sh[i] == 1 && i < n) {
				i++;
				cntX++;
			}
			cntXMax = max(cntX, cntXMax);
			i--;
		}
		else {
			cntO = 0;
			while (sh[i] == 0 && i < n) {
				i++;
				cntO++;
			}
			cntOMax = max(cntO, cntOMax);
			i--;
		}
	}
	if (a == 'X') return (cntXMax > cntOMax && cntXMax >= 5);
	return (cntOMax > cntXMax && cntOMax >= 5);
}
void result() {
	if (check()) {
		string s = "";
		for (int i = 0; i < n; i++) {
			if (sh[i]) s += "X";
			else s += "O";
		}
		res.push_back(s);
	}
}
void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		sh[i] = j;
		if (i == n - 1) result();
		else Try(i + 1);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> a;
		Try(0);
		sort(res.begin(), res.end());
		for (string x : res) cout << x << endl;
		res.clear();
	}
}
