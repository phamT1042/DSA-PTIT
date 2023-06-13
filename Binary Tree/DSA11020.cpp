#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, flag = 1; cin >> n;
        int a[n];
        cin >> a[0];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            if (a[i] <= a[i - 1]) flag = 0;
        }
        cout << flag << '\n';
    }
}