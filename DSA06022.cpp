#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n];
        set<int> res;
        for (int &x : a) {cin >> x; res.insert(x);}
        if (res.size() < 2) cout << "-1\n";
        else cout << *res.begin() << ' ' << *(++res.begin()) << endl;
	}
	return 0;
}