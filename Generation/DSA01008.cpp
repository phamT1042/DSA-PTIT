#include <bits/stdc++.h>
using namespace std;
int n, k, a[17];
void result() {
    int check = 0;
    for (int i = 0; i < n; i++) {
        check += a[i];
    }
    if (check == k) {
        for (int i = 0; i < n; i++) 
            cout << a[i];
        cout << endl;
    }
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
        cin >> n >> k;
        Try(0);
    }
    return 0;
}