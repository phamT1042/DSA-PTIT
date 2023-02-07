#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        cout << "Buoc " << i << ": ";
        int xep = a[i];
        int j = i - 1;
        while (a[j] > xep && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = xep;
        for (int k = 0; k <= i; k++) cout << a[k] << ' ';
        cout << endl;
    }
	return 0;
}