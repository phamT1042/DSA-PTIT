#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k, i; cin >> n >> k;
        int a[k + 1]; a[0] = n + 1;
        for (i = 1; i <= k; i++) cin >> a[i];
        i = k;
        while (a[i] == i) i--;
        if (!i) 
            for (i = k; i <= n; i++) cout << i << ' ';
        else {
            for (i; i >= 1; i--) 
                if (a[i] - 1 != a[i - 1]) break; 
            a[i]--;
            while (i <= k) {
                ++i;
                if (a[i] < n - k + i) a[i]++;
            }
            for (i = 1; i <= k; i++) cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}