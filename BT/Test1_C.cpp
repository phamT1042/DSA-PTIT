#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> a(n);
        for (string &x : a) cin >> x;
        stack<long long> st;
        if (a[0] == "+" || a[0] == "-" || a[0] == "*" || a[0] == "/") {
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/") {
                    long long c = st.top(); st.pop();
                    long long d = st.top(); st.pop();
                    if (a[i] == "+") st.push(c + d);
                    else if (a[i] == "-") st.push(c - d);
                    else if (a[i] == "*") st.push(c * d);
                    else st.push(c / d);
                }
                else {
                    st.push(stoll(a[i]));
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                if (a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/") {
                    long long c = st.top(); st.pop();
                    long long d = st.top(); st.pop();
                    if (a[i] == "+") st.push(c + d);
                    else if (a[i] == "-") st.push(d - c);
                    else if (a[i] == "*") st.push(c * d);
                    else st.push(d / c);
                }
                else {
                    st.push(stoll(a[i]));
                }
            }
        }
        cout << st.top() << '\n';
    }
	return 0; 
}