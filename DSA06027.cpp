#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        vector<string> res;
	    int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) swap(a[i], a[j]);
            }
            string s = "Buoc " + to_string(i + 1) + ": ";
            for (int k = 0; k < n; k++) {s += to_string(a[k]) + ' ';}
            res.push_back(s);
        }
        for (int i = res.size() - 1; i >= 0; i--) {
            cout << res[i] << endl;
        }
    }
	return 0;
}