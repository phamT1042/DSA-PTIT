#include <bits/stdc++.h>
using namespace std;
//Selection Sort
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        int res = 0;
        for (int &x : a) cin >> x;
        for (int i = 0; i < n - 1; i++) {
            int min = a[i];
            int vtMin = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < min) {
                    min = a[j];
                    vtMin = j;
                }
            }
            if (a[i] > min) {
                swap(a[i], a[vtMin]);
                res++;
            }
        }
        cout << res << endl;
    }
}