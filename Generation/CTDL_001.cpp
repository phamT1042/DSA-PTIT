#include <bits/stdc++.h>
using namespace std;
int x[1001], m, n;
void result () {
    for (int i = 1; i <= m; i++) cout << x[i] << ' ';
    int mid;
    if (n % 2 == 0) 
        mid = m;
    else 
        mid = m - 1;
    for (int i = mid; i >= 1; i--) cout << x[i] << ' ';
    cout << '\n';
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == m) result();
        else Try (i + 1);
    }
}
int main() {
    cin >> n;
    if (n == 1) 
        cout << "0\n1\n";
    else {
        m = n / 2;
        if (n % 2 == 1) m++;
        Try(1);
    }
    return 0;
}