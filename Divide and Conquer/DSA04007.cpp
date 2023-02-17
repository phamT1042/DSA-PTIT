#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int k; string a, b; cin >> k >> a >> b;
        if (a.length() > b.length()) swap(a, b);
        while (a.length() < b.length()) a = "0" + a;
        string res = ""; 
        int nho = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            int end = (a[i] - '0') + (b[i] - '0') + nho;
            if (end >= k) {
                end -= k;
                nho = 1;
            }
            else nho = 0;
            res = to_string(end) + res;
        }
        if (nho != 0) res = to_string(nho) + res;
        cout << res << endl;
    }
}