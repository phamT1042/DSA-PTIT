#include <bits/stdc++.h>
using namespace std;
int x[1001], m, n;
void result () {
    for (int i = 1; i <= m; i++) cout << x[i] << ' ';
    if (n % 2 == 0) {
        for (int i = m; i >= 1; i--) cout << x[i] << ' ';
        cout << endl;
    }
    else {
        for (int i = m - 1; i >= 1; i--) cout << x[i] << ' ';
        cout << endl;
    }
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
    if (n == 1) {
        cout << "0\n1\n";
    }
    else {
        m = n / 2;
        if (n % 2 == 1) m++;
        Try(1);
    }
    return 0;
}