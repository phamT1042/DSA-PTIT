#include <bits/stdc++.h>
using namespace std;
int binarySearch(int l, int r, int a[], int x) {
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        else if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return -1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
        int a[n];
        for (int &y : a) cin >> y;
        int check = binarySearch(0, n - 1, a, x);
        if (check == -1) cout << "-1\n";
        else {
            int i = check, j = check;
            while (a[i] == x) i--;
            while (a[j] == x) j++;
            cout << j - i - 1 << endl;
        }
	}
	return 0;
}