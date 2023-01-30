#include <bits/stdc++.h>
using namespace std;
void sinh (string x) {
    int i = x.length() - 1;
    while (i >= 0 && x[i] == '0') x[i--] = '1';
    if (i != -1) x[i] = '0';
    cout << x << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string x; cin >> x;
        sinh(x);
    }
    return 0;
}