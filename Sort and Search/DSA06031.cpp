#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        multiset<int> check;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i < k) {
                check.insert(a[i]);
            }
        }
        cout << *check.rbegin() << ' ';
        for (int i = k; i < n; i++) {
            check.insert(a[i]);
            check.erase(check.find(a[i - k]));
            cout << *check.rbegin() << ' ';
        }
        cout << endl;
    }
	return 0;
}