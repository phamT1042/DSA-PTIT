#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
void nhanMT(vector<long long> a[], vector<long long> b[]) {
    vector<long long> c[2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i].push_back(0);
            for (int k = 0; k < 2; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = c[i][j];
        }
    }
}
void fibonacci(int n) {
    vector<long long> dv[2] = {{1, 0}, {0, 1}};
    vector<long long> a[2] = {{1, 1}, {1, 0}}; 
    while (n) {
        if (n % 2 == 1) nhanMT(dv, a);
        nhanMT(a, a);
        n /= 2;
    }
    cout << dv[0][1] << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fibonacci(n);
    }
}