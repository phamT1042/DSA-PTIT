#include <bits/stdc++.h>
using namespace std;
int main() {
        int n; cin >> n;
        int a[n];
        vector<int> up, down;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2 == 0) up.push_back(a[i]);
            else down.push_back(a[i]);
        }
        sort(up.begin(), up.end());
        sort(down.begin(), down.end(), greater<int>());
        int i = 0, j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) cout << up[j++] << ' ';
            else cout << down[k++] << ' ';
        }
	return 0;
}