#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<string> a;
    string s;
    while (getline(cin, s)) {
        if (s[0] == 'p') {
            if (s[1] == 'u')
                a.push(s.substr(5, s.length() - 5));
            else a.pop();
        }
        else {
            vector<string> v;
            if (a.empty()) cout << "empty";
            else {
                while (!a.empty()) {
                    v.push_back(a.top());
                    a.pop();
                }
                reverse(v.begin(), v.end());
                for (string x : v) {cout << x << ' '; a.push(x);}
                cout << "\n";
            }
        }
    }
}