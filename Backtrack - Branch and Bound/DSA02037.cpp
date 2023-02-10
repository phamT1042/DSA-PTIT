#include<bits/stdc++.h>
using namespace std;
int n, sh[15], sang[1485];
void sangNT() {
    for (int i = 0; i < 1485; i++) sang[i] = 1;
    sang[0] = sang[1] = 0;
    for (int i = 2; i < 39; i++) {
        if (sang[i]) {
            for (int j = i * i; j < 1485; j += i) {
                sang[j] = 0;
            }
        }
    }
}
void result(int a[]) {
    int sum = 0;
    string s = "";
    for (int i = 0; i < n; i++) {
        sum += a[i] * sh[i];
        if (sh[i])
            s += to_string(a[i]) + ' ';
    }
    if (sang[sum]) cout << s << endl;
}
void Try (int i, int a[]) {
    for (int j = 0; j <= 1; j++) {
        sh[i] = j;
        if (i == n - 1) result(a);
        else Try(i + 1, a);
    }
}
int main() {
    sangNT();
    int t; cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n, greater<int>());
        Try(0, a);
    }
}