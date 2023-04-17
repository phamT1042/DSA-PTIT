#include<bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    stack<char> st;
    string res = "";
    for (char x : s) {
        if (x == '<') {
            if (res != "") {
                st.push(res[res.length() - 1]);
                res.pop_back();
            }
        } 
        else if (x == '>') {
            if (st.size()) {
                res += st.top();
                st.pop();
            }
        }
        else if (x == '-') {
            if (res != "") res.pop_back();
        }
        else res += x;
    }
    while (st.size()) {
        res += st.top();
        st.pop();
    }
    cout << res;
    return 0;
}