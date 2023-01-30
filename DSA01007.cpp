#include <bits/stdc++.h>
using namespace std;
int n, a[11];
void result() {
    for (int i = 0; i < n; i++) {
        if (a[i]) cout << "B";
        else cout << "A";
    }
    cout << " ";
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n - 1) result ();
        else Try (i + 1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        Try(0);
        cout << endl;
    }
    return 0;
}