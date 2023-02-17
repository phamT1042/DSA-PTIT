#include<bits/stdc++.h>
using namespace std;
string binarySearch (int a[], int l, int r, int k) {
    if (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == k) return to_string(m + 1);
        else if (a[m] > k) return binarySearch(a, l, m - 1, k);
        return binarySearch(a, m + 1, r, k);
    }
    return "NO";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for (int &x : a) cin >> x;
        cout << binarySearch(a, 0, n - 1, k) << endl;
    }
}