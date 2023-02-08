#include <bits/stdc++.h>
using namespace std;
int flag = 0;
vector<string> res;
void result(int s[], int n, int k) {
    int cntA = 0, cntAmax = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            cntA++;
        }
        cntAmax = max(cntA, cntAmax);
        if (s[i] == 1) cntA = 0;
    }
    if (cntAmax != k) return;
    string tmp = "";
    for (int i = 0; i < n; i++) {
        if (s[i]) tmp += "B";
        else tmp += "A";
    }
    res.push_back(tmp);
}
void sinhNP(int s[], int n, int k) {
    result(s, n, k);
    int i = n - 1;
    while (i >= 0 && s[i] == 1) s[i--] = 0;
    if (i == -1) {
        flag = 1;
        return;
    }
    s[i] = 1;
}
int main() {
    int n, k;
    cin >> n >> k;
    int s[n];
    memset(s, 0, sizeof(s));
    while (!flag) {
        sinhNP(s, n, k);
    }
    cout << res.size() << endl;
    for (string x : res) cout << x << endl;
    return 0;
}