#include<bits/stdc++.h>
using namespace std;
int n, sh[15], k;
void result(int a[]) {
    for (int i = 1; i <= k; i++) 
        cout << a[sh[i] - 1] << ' ';
    cout << '\n';
}
void Try (int i, int a[]) {
    for (int j = sh[i - 1] + 1; j <= n - k + i; j++) {
        sh[i] = j;
        if (i == k) result(a);
        else Try(i + 1, a);
    }
}
int main() {
    int t; cin >> t;
    sh[0] = 0;
    while (t--) {
        cin >> n >> k;
        int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n);
        Try(1, a);
    }
}