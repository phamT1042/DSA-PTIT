#include <bits/stdc++.h>
using namespace std;
void sinh (int n, int k, int a[]) {
    set<int> check;
    for (int i = 0; i < k; i++) check.insert(a[i]);
    int data1 = check.size();
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1) i--;
    if (i == -1) cout << k << endl;
    else {
        a[i]++;
        for (int j = i + 1; j < k; j++) a[j] = a[j - 1] + 1;
        for (int i = 0; i < k; i++) check.insert(a[i]);
        cout << check.size() - data1 << endl;
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int a[k];
        for (int &x : a) cin >> x;
        sinh(n, k, a);
    }
    return 0;
}