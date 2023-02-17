#include<bits/stdc++.h>
using namespace std;
int maxCrossingSum (int a[], int l, int m, int r) {
    int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }
    return leftSum + rightSum;
}
int maxChild (int a[], int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) / 2;
    return max (maxChild(a, l, m), max(maxChild(a, m + 1, r), maxCrossingSum(a, l, m, r)));
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        cout << maxChild(a, 0, n - 1) << endl;
    }
}