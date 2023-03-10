#include<bits/stdc++.h>
using namespace std;

vector<string> tachBT (string s) {
    vector<string> a;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, '+')) {
        a.push_back(tmp);
    }
    return a;
}
int heSo[10001];
int main() {
    int t; cin >> t;
    cin.ignore();
    while (t--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        vector<string> soHang1, soHang2;
        soHang1 = tachBT(s1);
        soHang2 = tachBT(s2);
        int maxMu = 0;
        memset(heSo, 0, sizeof(heSo));
        for (string x : soHang1) {
            int i = 1;
            for (i; i < x.length(); i++) {
                if (x[i] == '*') break;
            } 
            heSo[x[x.length() - 1] - '0'] += stoi(x.substr(0, i));
            if (x[x.length() - 1] - '0' > maxMu) maxMu = x[x.length() - 1] - '0';
        }
        for (int i = maxMu; i >= 0; i--) {
            if (heSo[i] > 0) cout << heSo[i] << "*x^" << i << " + ";
        }
    }
}