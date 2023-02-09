#include<bits/stdc++.h>
using namespace std;
int a[11], n;
bool used[11];
bool check() {
    for (int i = 0; i < n - 1; i++) {
        if (abs(a[i] - a[i + 1]) == 1) return false;
    }
    return true;
}
void result() {
    if (check()) {
        for (int i = 0; i < n; i++) cout << a[i];
        cout << endl;
    }
}
void Try (int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = true;
            if (i == n - 1) result();
            else Try(i + 1);
            used[j] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        Try(0);
    }
}