#include <bits/stdc++.h>
using namespace std;
//|1 1 0 0|   |F(N-1)|   |F(N)  |   |1 1 0 0|^(N-1)   |F(1)|
//|0 1 1 1| * |T(N)  | = |T(N+1)| = |0 1 1 1|       * |T(2)|
//|0 1 0 0|   |T(N-1)|   |T(N)  |   |0 1 0 0|         |T(1)|
//|0 0 1 0|   |T(N-2)|   |T(N-1)|   |0 0 1 0|         |T(0)|
long long MOD = 1e15 + 7;
long long binMul(long long a, long long b) {
    if(b == 0) return 0;
    long long res = binMul(a, b / 2) % MOD;
    res += res; res %= MOD;
    if(b % 2) {
        res += a; res %= MOD;
    }
    return res;
}
void nhanMT (long long a[4][4], long long b[4][4]) {
    long long res[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                res[i][j] += binMul(a[i][k], b[k][j]) % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) a[i][j] = res[i][j];
}
long long Tribonacci(int n) {
    long long res[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    long long a[4][4] = {{1, 1, 0, 0}, {0, 1, 1, 1}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    while (n) {
        if (n % 2) nhanMT(res, a);
        nhanMT(a, a);
        n /= 2;
    }
    return ((res[0][0] + res[0][2]) % MOD + (res[0][1] * 2) % MOD) % MOD;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (!n) cout << 0;
        else cout << Tribonacci(n - 1);
        cout << '\n';
    }
    return 0;
}
