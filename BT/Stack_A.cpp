#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<string> save;
        for (char x : s) save.push_back(string(1, x));
        stack<int> pos;
        for (int i = 0; i < s.length(); i++) {
            if (save[i] == "(") pos.push(i);
            else if (save[i] == ")") {
                if (pos.empty()) save[i] = "-1";
                else {
                    save[pos.top()] = "0";
                    save[i] = "1";
                    pos.pop();
                }
            }
        }
        while (pos.size()) {
            save[pos.top()] = "-1";
            pos.pop();
        }
        for (string x : save) cout << x;
        cout << '\n';
    }
    return 0;
}