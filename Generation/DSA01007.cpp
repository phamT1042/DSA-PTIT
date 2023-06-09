#include <bits/stdc++.h>
using namespace std;
int n;
char a[11];
void result() {
    for (int i = 0; i < n; i++) cout << a[i];
    cout << ' ';
}
void Try (int i) {
    for (char j = 'A'; j <= 'B'; j++) {
        a[i] = j;
        if (i == n - 1) result();
        else Try(i + 1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        Try(0);
        cout << '\n';
    }
    return 0;
}