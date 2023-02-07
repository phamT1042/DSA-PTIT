#include<bits/stdc++.h>
using namespace std;
int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        queue<string> sinh;
        stack<string> res;
        sinh.push("6");
        sinh.push("8");
        res.push("6");
        res.push("8");
        string out = "6";
        while (1) {
            out = sinh.front();
            if (out.length() == n) break; 
            sinh.pop();
            sinh.push(out + "6");
            sinh.push(out + "8");
            res.push(out + "6");
            res.push(out + "8");
        }
        while (!res.empty()) {
            cout << res.top() << ' ';
            res.pop();
        }
        cout << endl;
    }
    return 0;
}
