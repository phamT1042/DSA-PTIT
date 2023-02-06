#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        long long a[n1], b[n2], c[n3];
        for (long long &x : a) cin >> x;
        for (long long &x : b) cin >> x;
        for (long long &x : c) cin >> x;
        int i = 0, j = 0, k = 0;
        set<long long> res;
        while (i < n1 && j < n2 && k < n3) {
            if (a[i] == b[j] && a[i] == c[k]) {
                res.insert(a[i]);
                i++; j++; k++;
            }
            else if (a[i] < b[j]) i++;
            else if (b[j] < c[k]) j++;
            else k++;
        }
        if (res.empty()) cout << "-1\n";
        else {
            for (int x : res) cout << x << ' ';
            cout << endl;
        }
	}
	return 0;
}