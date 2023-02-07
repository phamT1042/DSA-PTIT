#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<string> res;
	int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        int xep = a[i];
        int j = i - 1;
        while (a[j] > xep && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = xep;
        string s = "Buoc " + to_string(i) + ": ";
        for (int k = 0; k <= i; k++) {s += to_string(a[k]) + ' ';}
        res.push_back(s);
    }
    for (int i = res.size() - 1; i >= 0; i--) 
        cout << res[i] << endl;
	return 0;
}