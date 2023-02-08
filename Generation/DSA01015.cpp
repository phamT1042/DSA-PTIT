#include <bits/stdc++.h>
using namespace std;
string timBoi (int n) {
    queue<string> boi;
    boi.push("9");
    while (1) {
        string tmp = boi.front(); boi.pop();
        if (stoll(tmp + "0") % n == 0) return tmp + "0";
        boi.push(tmp + "0");
        if (stoll(tmp + "9") % n == 0) return tmp + "9";
        boi.push(tmp + "9");
    }
    return "";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (9 % n == 0) cout << "9\n";
        else {    
            cout << timBoi(n) << endl;
        }
    }
    return 0;
}