#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    cin.ignore();
    stack<string> a;
    while (t--) {
        string s; getline(cin, s);
        if (s[1] == 'U')
            a.push(s.substr(5, s.length() - 5));
        else if (s[1] == 'O') {
            if (!a.empty()) a.pop();
        }
        else {
            if (a.empty()) cout << "NONE";
            else {
                cout << a.top();
            }
            cout << "\n";
        }
    }
}