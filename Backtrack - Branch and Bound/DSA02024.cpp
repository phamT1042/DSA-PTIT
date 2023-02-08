#include<bits/stdc++.h>
using namespace std;
int n, a[21], s[21];
vector<string> res;
void result() {
    int check = INT_MIN, cnt = 0;
    string tmp = "";
    for (int i = 0; i < n; i++) {
        if (s[i]) {
            cnt++;
            if (a[i] > check) {
                check = a[i];
                tmp += to_string(a[i]) + ' ';
            }
            else return;
        }
    }
    if (cnt >= 2)
        res.push_back(tmp);
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        s[i] = j;
        if (i == n - 1) result();
        else Try(i + 1);
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    Try(0);
    sort(res.begin(), res.end());
    for (string x : res) cout << x << endl;
}