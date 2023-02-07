#include<bits/stdc++.h>
using namespace std;
int binaryTach(int a[], int l, int r, int n) {
    int m;
    while (l <= r) {
        m = (l + r) / 2;
        if (a[m] > a[n - 1]) l = m + 1;
        else r = m - 1;
    }
    return m;
}
int binarySearch (int a[], int l, int r, int x) {
    int m;
    while (l <= r) {
        m = (l + r) / 2;
        if (a[m] == x) return m;
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return m;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		int a[n];
        for (int &y : a) cin >> y;
        int posTach = binaryTach(a, 0, n - 1, n);
        if (posTach == 0) {
            cout << binarySearch(a, 0, n - 1, x) + 1 << endl;
        } 
        else {
            if (x < a[n - 1]) cout << binarySearch(a, posTach, n - 1, x) + 1 << endl;
            else cout << binarySearch(a, 0, posTach - 1, x) + 1 << endl;
        }
	}
	return 0;
}