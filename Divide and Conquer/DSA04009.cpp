#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
void nhanMT(vector<long long> a[], vector<long long> b[], int n) {
    vector<long long> c[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i].push_back(0);
            for (int k = 0; k < n; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = c[i][j];
        }
    }
}
void result(vector<long long> a[], int k, int n) {
    vector<long long> res[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) res[i].push_back(1);
            else res[i].push_back(0);
        }
    }
    while (k) {
        if (k % 2 == 1) nhanMT(res, a, n);
        nhanMT(a, a, n);
        k /= 2;
    }
    for (vector<long long> x : res) {
        for (long long y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        long long x;
        vector<long long> a[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x;
                a[i].push_back(x);
            }
        }
        result(a, k, n);
    }
}