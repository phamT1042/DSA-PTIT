#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        long long a = 0, b = 0;
        int mu = 1;
        for (int i = s1.length() - 1; i >= 0; i--) {
            a += (s1[i] - '0') * mu;
            mu *= 2;
        }
        mu = 1;
        for (int i = s2.length() - 1; i >= 0; i--) {
            b += (s2[i] - '0') * mu;
            mu *= 2;
        }
        cout << a * b << endl;
    }
}