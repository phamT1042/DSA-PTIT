#include<bits/stdc++.h>
using namespace std;
int a[16];
int k, n, i;
void result() {
    for (int h = 0; h < i; h++) cout << a[h];
    for (int h = i - 1; h >= 0; h--) cout << a[h];
    cout << ' ';
}
void Try(int j) {
    for (int h = 0; h <= 1; h++) {
        a[j] = h;
        if (j == i - 1) result();
        else Try(j + 1);
    }
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
        k = n / 2;
        i = 1;
        for (i; i <= k; i++) {
            Try(0);
        }
        cout << endl;
	}
}
