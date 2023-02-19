#include<bits/stdc++.h>
using namespace std;
long long a[51];
long long Try (int step, long long k, long long n) {
    if (step == 1)  return n % 2;
    if (k == a[step - 1] + 1) return n % 2;
    if (k > a[step - 1] + 1) return Try(step - 1, k - a[step - 1] - 1, n / 2);
    return Try(step - 1, k, n / 2);
}
int main() {
    int t; cin >> t;
    while (t--) {
        a[1] = 1;
        long long n, l, r;
        cin >> n >> l >> r;
        int cnt = 2;
        long long test = n / 2;
        while (test > 0) {
            a[cnt] = 2 * a[cnt - 1] + 1;
            test /= 2;
            cnt++;
        }
        cnt--;
        long long res = 0;
        for (long long i = l; i <= r; i++) res += Try(cnt, i, n);
        cout << res << endl;
    }
}