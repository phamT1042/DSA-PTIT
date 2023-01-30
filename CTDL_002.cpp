#include <bits/stdc++.h>
using namespace std;
int x[1001], k, n, a[1001], res = 0;
void result () {
    int check = 0;
    for (int i = 1; i <= n; i++) {
        check += a[i] * x[i];
        if (check > k) return;
    }
    if (check == k) {
        res++;
        for (int i = 1; i <= n; i++) {
            if (x[i]) cout << a[i] << ' ';
        }
        cout << endl;
    }
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) result();
        else Try (i + 1);
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(1);
    cout << res;
    return 0;
}