#include<bits/stdc++.h>
using namespace std;
int a[11], n;
bool used[11];
void result() {
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << '\n';
}
void Try (int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j] && abs(a[i - 1] - j) != 1) {
            a[i] = j;
            used[j] = true;
            if (i == n) result();
            else Try(i + 1);
            used[j] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    a[0] = 15;
    while (t--) {
        cin >> n;
        Try(1);
    }
}