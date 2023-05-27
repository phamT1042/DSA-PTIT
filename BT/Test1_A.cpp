#include<bits/stdc++.h>
using namespace std;
int n, m, used[10], a[10], st = 0;
void result () {
    st++;
    if (!(st % m)) {
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << '\n';
    }
}
void Try (int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = 1;
            if (i == n - 1) result();
            else Try (i + 1);
            used[j] = 0;
        }
    }
}
int main() {
    cin >> n >> m;
    Try(0);
	return 0; 
}