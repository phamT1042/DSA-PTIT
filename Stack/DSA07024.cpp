#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long a[n];
        long long dmax = 0;
        for (long long &x : a) cin >> x;
        stack<long long> st;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (a[i] < a[st.top()]) {
                int idx = st.top(); st.pop();
                if (st.empty()) {
                    if (i >= a[idx]) dmax = max(dmax, a[idx]);
                    break;
                }
                else {
                    if (i - st.top() - 1 >= a[idx]) 
                        dmax = max(dmax, a[idx]);
                }
            }
            st.push(i);
        }
        while (!st.empty()) {
            int idx = st.top(); st.pop();
            if (st.empty()) {
                if (n >= a[idx]) 
                    dmax = max(dmax, a[idx]);
                break;
            }
            else {
                if (n - st.top() - 1 >= a[idx])  
                    dmax = max(dmax, a[idx]);
            }
        }
        cout << dmax << '\n';
    }
}