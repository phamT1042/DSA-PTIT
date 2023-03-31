#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ngoac;
int sh[10];
string s;
set<string> res;
void in() {
    string tmp = s;
    for (int i = 0; i < ngoac.size(); i++) {
        if (!sh[i]) {
            tmp[ngoac[i].first] = ' ';
            tmp[ngoac[i].second] = ' ';
        } 
    }
    string t = "";
    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] != ' ') t += tmp[i];
    }
    if (t != s)
        res.insert(t);
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        sh[i] = j;
        if (i == ngoac.size() - 1) in();
        else Try(i + 1);
    }
}
int main() {
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        if (s[i] == ')') {
            ngoac.push_back({st.top(), i});
            st.pop();
        }
    }
    Try(0);
    for (string x : res) cout << x << endl;
    return 0;
}