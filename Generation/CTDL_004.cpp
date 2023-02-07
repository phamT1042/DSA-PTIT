#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> check[n];
    int a[n]; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        check[i].push_back(1);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                for (int x : check[j]) {
                    check[i].push_back(x + 1);
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int x : check[i]) {
            if (x == k) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
