#include<bits/stdc++.h>
using namespace std;
int calculator (int i, string a[]) {
    if (a[i] == "+")
        return calculator(2 * i + 1, a) + calculator(2 * i + 2, a);
    if (a[i] == "-")
        return calculator(2 * i + 1, a) - calculator(2 * i + 2, a);
    if (a[i] == "*")
        return calculator(2 * i + 1, a) * calculator(2 * i + 2, a);
    if (a[i] == "/")
        return calculator(2 * i + 1, a) / calculator(2 * i + 2, a);
    return stoi(a[i]);
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a[n];
        for (string &x : a) cin >> x;
        cout << calculator(0, a) << '\n';
    }
    return 0;
}