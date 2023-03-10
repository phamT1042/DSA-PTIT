#include<bits/stdc++.h>
using namespace std;

bool del (char a, char b) {
    if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}') return true;
    return false;
}
string check(string s) {
    stack<char> q;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') q.push(s[i]);
        else {
            if (q.empty()) return "NO";
            else {
                if (del(q.top(), s[i])) q.pop();
                else return "NO";
            }
        }
    }
    if (q.empty()) return "YES";
    return "NO";
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << check(s) << endl;
    }
}