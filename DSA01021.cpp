#include<bits/stdc++.h>
using namespace std;
void sinh (int a[], int n, int k, set<int> add) {
    int i = k, size = add.size();
    while (i > 0 && a[i] == n - k + i) i--;
    if (i == 0) {
        cout << k << endl;
    }
    else {
        a[i]++;
        for (int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
        for (int i = 1; i <= k; i++) add.insert(a[i]);
        cout << add.size() - size << endl;
    }
}
int main () {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int a[k + 1];
        set<int> add;
        for (int i = 1; i <= k; i++) {cin >> a[i]; add.insert(a[i]);}
        sinh(a, n, k, add);
    }
    return 0;
}
