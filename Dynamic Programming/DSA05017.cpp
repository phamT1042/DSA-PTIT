#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n], tang[n], giam[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tang[i] = a[i];
            giam[i] = a[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    tang[i] = max(tang[i], tang[j] + a[i]);
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    giam[i] = max(giam[i], giam[j] + a[i]);
                }
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, tang[i] + giam[i] - a[i]); 
        }
        cout << res << endl;
    }
}