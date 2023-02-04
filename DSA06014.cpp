#include <bits/stdc++.h>
using namespace std;
bool sang[1000001];
void sangNT() {
    for (int i = 0; i < 1000001; i++) sang[i] = true;
    sang[0] = sang[1] = false;
    for (int i = 2; i < 1000; i++) {
        if (sang[i]) {
            for (int j = i * i; j < 1000001; j += i) {
                sang[j] = false;
            }
        }
    }
}
int main() {
    sangNT();
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
        int flag = 0, i = 2;
        for (i; i < n - 1; i++) {
            if (sang[i] && sang[n - i]) {
                flag = 1;
                break;
            }
        }
        if (flag) cout << i << ' ' << n - i << endl;
        else cout << "-1\n";
	}
	return 0;
}