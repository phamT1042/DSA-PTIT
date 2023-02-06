#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
    vector<string> res;
	int n, flag; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        flag = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				flag = 1;
				swap(a[j], a[j + 1]);
			}
		}
		if (flag) {
            string s = "Buoc " + to_string(i + 1) + ": ";
            for (int k = 0; k < n; k++) {s += to_string(a[k]) + ' ';}
            res.push_back(s);
		}
    }
    for (int i = res.size() - 1; i >= 0; i--) 
        cout << res[i] << endl;
    }
	return 0;
}