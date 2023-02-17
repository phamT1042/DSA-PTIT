#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long res (long long a, long long b) {
    if (b == 0) return 1;
    long long tmp = res (a, b / 2);
    if (b % 2 == 1) return ((tmp * tmp) % MOD * a) % MOD;
    else return (tmp * tmp) % MOD;
}
int main() {
    long long a, b;
    while (1) {
        cin >> a >> b;
        if (a == b && b == 0) return 0;
        cout << res(a, b) << endl;
    }
}