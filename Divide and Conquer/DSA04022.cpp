#include<bits/stdc++.h>
using namespace std;
long long a[27];
int Try(int n, long long k) {
    if (k == a[n] / 2 + 1) return n;
    if (k > a[n] / 2 + 1) return Try (n - 1, k - a[n] / 2 - 1);
    return Try (n - 1, k);
}
int main() {
    a[1] = 1;
    for (int i = 2; i <= 26; i++) a[i] = a[i - 1] * 2 + 1;
    int t; cin >> t;
    while (t--) {
        int n; long long k; cin >> n >> k;
        cout << char (Try(n, k) + 'A' - 1) << endl;
    }
}