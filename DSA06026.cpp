#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, flag; cin >> n;
	int a[n];
    for (int &x : a) cin >> x;
	for (int i = 0; i < n; i++) {
		flag = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				flag = 1;
				swap(a[j], a[j + 1]);
			}
		}
		if (flag) {
			cout << "Buoc " << i + 1 << ": ";
			for (int x : a) cout << x << ' ';
			cout << endl;
		}
		else break;
	}
	return 0;
}