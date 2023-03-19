#include<bits/stdc++.h>
using namespace std;
long long a[46];
long long Try (int n, long long k) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (k > a[n - 1]) return Try(n - 1, a[n - 1]) + Try(n - 2, k - a[n - 1]);
    return Try(n - 1, k);
}
int main() {
    a[0] = a[1] = 1;
    for (int i = 2; i < 46; i++) a[i] = a[i - 1] + a[i - 2];
    int t; cin >> t;
    while (t--) {
        int n; long long k;
        cin >> n >> k;
        cout << Try(n, k) << endl;
    }
}
