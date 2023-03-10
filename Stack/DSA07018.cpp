#include<bits/stdc++.h>
using namespace std;
vector<string> tachBT (string s1, string s2) {
    vector<string> a;
    stringstream ss(s1);
    string tmp;
    while (getline(ss, tmp, ' ')) a.push_back(tmp);
    stringstream ss1(s2);
    while (getline(ss1, tmp, ' ')) a.push_back(tmp);
    return a;
}
int main() {
    int t; cin >> t;
    cin.ignore();
    while (t--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        vector<string> tongDaThuc;
        tongDaThuc = tachBT(s1, s2);
        map<int, int, greater<int>> soHang;
        for (string x : tongDaThuc) {
            if (x[0] == '+') continue;
            int heSo, bac;
            for (int i = 1; i < x.length(); i++) {
                if (x[i] == '*') heSo = stoi(x.substr(0, i));
                if (x[i] == '^') {
                    bac = stoi(x.substr(i + 1, x.length() - i - 1));
                    break;
                }
            }
            soHang[bac] += heSo;
        }
        int n = soHang.size(), i = 0;
        for (auto it : soHang) {
            cout << it.second << "*x^" << it.first;
            i++;
            if (i < n) cout << " + ";
            else cout << "\n";
        }
    }
}