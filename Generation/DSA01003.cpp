#include<bits/stdc++.h>
using namespace std;
void sinh (int a[], int n) {
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1]) i--;
    if (i == -1) {
        for (int j = 1; j <= n; j++) cout << j << ' ';
    }
    else {
        int k = n - 1;
        while (a[i] >= a[k]) k--;
        swap(a[i], a[k]);
        int l = i + 1, r = n - 1;
        while (l < r) {
            swap(a[l++], a[r--]);
        }
        for (int j = 0; j < n; j++) cout << a[j] << ' ';
    }
    cout << endl;
}
int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        sinh(a, n);
    }
    return 0;
}
