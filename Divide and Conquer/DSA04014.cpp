#include<bits/stdc++.h>
using namespace std;
long long merge(long long a[], int l, int m, int r) {
    vector<long long> x(a + l, a + m + 1);
    vector<long long> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    long long cnt = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            a[l++] = x[i++];
        }
        else {
            cnt += x.size() - i;
            a[l++] = y[j++];}
    }
    while (i < x.size()) a[l++] = x[i++];
    while (j < y.size()) a[l++] = y[j++];
    return cnt;
}
long long mergeSort(long long a[], int l, int r) {
    long long cnt = 0;
    if (l < r) {
        int m = (l + r) / 2;
        cnt += mergeSort(a, l, m);
        cnt += mergeSort(a, m + 1, r);
        cnt += merge(a, l, m, r);
    }
    return cnt;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long a[n];
        for (long long &x : a) cin >> x;
        cout << mergeSort(a, 0, n - 1) << endl;
    }
}