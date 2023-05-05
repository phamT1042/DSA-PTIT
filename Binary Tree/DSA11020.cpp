#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, flag = 1; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] >= a[i]) {
                flag = 0;
                break;
            }
        }
        cout << flag << '\n';
    }
}