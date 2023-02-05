#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		int a[n];
        for (int &y : a) cin >> y;
        if (binary_search(a, a + n, x)) cout << "1\n";
        else cout << "-1\n";
	}
	return 0;
}