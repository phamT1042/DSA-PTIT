#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        stack<int> s;
        int a[n], b[n], c[n];
        //b: ptu bên phải đầu tiên lớn hơn
        //c: ptu bên phải đầu tiên nhỏ hơn
        for (int &x : a) cin >> x;
        s.push(0);
        for (int i = 1; i < n; i++) {
            while (s.size() && a[s.top()] < a[i]) {
                b[s.top()] = i;
                s.pop();
            }
            s.push(i);    
        }
        while (s.size()) {
            b[s.top()] = -1;
            s.pop();
        }
        s.push(0);
        for (int i = 1; i < n; i++) {
            while (s.size() && a[s.top()] > a[i]) {
                c[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }      
        while (s.size()) {
            c[s.top()] = -1;
            s.pop();
        }
        for (int i = 0; i < n; i++) {
            if (b[i] != -1)
                if (c[b[i]] != -1) cout << a[c[b[i]]] << ' ';
                else cout << -1 << ' ';
            else cout << -1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}