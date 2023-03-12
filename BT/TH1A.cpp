#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		long long p; cin >> p;
		if (p < 10) cout << p << endl;
		else {
			string n = "";
			int i = 9;
			while (p > 1 && i >= 2) {
				while (p % i == 0) {
					n += to_string(i);
					p /= i;
				}
				i--;
			}
			if (n == "" || p > 10) cout << "-1" << endl;
			else {
				reverse(n.begin(), n.end());
				cout << n << endl;
			} 
		}
	}
	return 0;
}
