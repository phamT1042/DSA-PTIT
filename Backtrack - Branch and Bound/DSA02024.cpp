#include<bits/stdc++.h>
using namespace std;
int n, a[21];
vector<int> save;
vector<string> res;
void result() {
    string tmp = "";
    for (int x : save) tmp += to_string(x) + ' ';
    res.push_back(tmp);
}
void Try (int i) {
    for (int j = i + 1; j <= n; j++) {
        if (a[j] > a[i]) {
            save.push_back(a[j]);
            if (save.size() > 1) result();
            Try(j);
            save.pop_back();
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(0);
    sort(res.begin(), res.end());
    for (string x : res) cout << x << endl;
}