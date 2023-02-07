#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[k + 1]; a[0] = 0;
        for (int i = 1; i <= k; i++) cin >> a[i];
        int j = k;
        while(a[j - 1] + 1 == a[j] && j >= 1) j--;
        if (j == 0) {
            for (int i = n - k + 1; i <= n; i++)
                cout << i << ' ';
        }
        else {
            a[j]--;
            for (int i = j + 1; i <= k; i++) a[i] = n - k + i; 
            for (int i = 1; i <= k; i++) cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}