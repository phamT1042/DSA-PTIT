#include<bits/stdc++.h>
using namespace std;
int search (int a[], int b[], int n, int m, int k) {
    int i = 0, j = 0, l = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            l++;
            if (l == k) return a[i];
            i++;
        }
        else if (a[i] > b[j]) {
            l++;
            if (l == k) return b[j];
            j++;
        }
        else {
            l++;
            if (l == k) return b[j];
            j++;
            l++;
            if (l == k) return a[i];
            i++;
        }
    }
    while (i < n) {
        l++;
        if (l == k) return a[i];
        i++;
    }
    while (j < m) {
        l++;
        if (l == k) return b[j];
        j++;
    }
    return -1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int a[n], b[m];
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        cout << search(a, b, n, m, k) << endl;
    }
}