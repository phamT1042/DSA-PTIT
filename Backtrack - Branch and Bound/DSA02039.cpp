#include<bits/stdc++.h>
using namespace std;
int sh[11], n, ssh, flag;
vector<string> res;
void sinh() {
    string s = "(";
    for (int i = 1; i <= ssh; i++) {
        s += to_string(sh[i]);
        if (i < ssh) s += ' ';
    }
    s += ")";
    res.push_back(s);
    int i = ssh;
    while (i >= 1 && sh[i] == 1) i--;
    if (i == 0) {
        flag = 1;
        return;
    }
    sh[i]--;
    int number_of_digit_1 = ssh - i;
    number_of_digit_1++;
    ssh = i;
    int q = number_of_digit_1 / sh[i];
    int r = number_of_digit_1 % sh[i];
    while (q--) {
        ssh++;
        sh[ssh] = sh[i];
    }
    if (r) {
        ssh++;
        sh[ssh] = r;
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        ssh = 1, flag = 0;
        sh[1] = n;
        while (!flag) {
            sinh();
        }
        cout << res.size() << endl;
        for (string x : res) cout << x << ' ';
        cout << endl;
        res.clear();
    }
}