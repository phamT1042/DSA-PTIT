#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1) cout << ' ';
        }
        cout << "]\n";
        for (int i = n - 1; i >= 1; i--) {
            cout << '[';
            for (int j = 0; j < i; j++) {
                a[j] += a[j + 1];
                cout << a[j];
                if (j < i - 1) cout << ' ';
            }
            cout << ']' << '\n';
        }
    }
}