#include<bits/stdc++.h>
using namespace std;
int n, flag = 0;
string x = "8";
bool check (string x) {
    if (x[n - 1] == '8') return false;
    if (x.find("88") != string::npos || x.find("6666") != string::npos) return false;
    return true;
}
void sinh () {
    int i = n - 1;
    while (i >= 0 && x[i] == '8') x[i--] = '6';
    if (i == -1) {
        flag = 1;
        return;
    }
    x[i] = '8';
    if (check(x)) cout << x << '\n';
}
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) x += "6";
    while (!flag) sinh();
    return 0;
}