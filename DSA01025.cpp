#include<bits/stdc++.h>
using namespace std;
int n, k;
int sh[17];
void result() {
    for (int i = 1; i <= k; i++) {
        cout << (char)(sh[i] + 64);
    }
    cout << endl;
}
void Try (int i) {
    for (int j = sh[i - 1] + 1; j <= n - k + i; j++) {
        sh[i] = j;
        if (i == k) result();
        else Try(i + 1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        Try(1);
    }
}