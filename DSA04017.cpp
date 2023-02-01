#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, i; cin >> n;
        int a[n], b[n];
        for (int &x : a) cin >> x;
        for (i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        b[n - 1] = -1;
        i = 0;
        while (i < n) {
            if (a[i] != b[i]) break;
            i++;
        }
        cout << ++i << endl;
	}
	return 0;
}