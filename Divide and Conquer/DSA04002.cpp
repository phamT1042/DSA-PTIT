#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long result (long long n, long long k) {
    if (k == 0) return 1;
    long long tmp = result(n, k / 2) % MOD;
    if (k % 2 == 1) return ((tmp * tmp) % MOD * n) % MOD;
    else return (tmp * tmp) % MOD;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string n1, n2 = ""; cin >> n1;
        for (int i = n1.length() - 1; i >= 0; i--) {
            n2 += n1[i];
        }
        long long n, k;
        n = stoll(n1);
        k = stoll(n2);
        cout << result(n, k) << endl;
    }
}