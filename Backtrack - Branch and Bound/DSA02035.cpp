#include<bits/stdc++.h>
using namespace std;
//Hoán vị theo cột các số
int k, sh[9], res = INT_MAX;
vector<string> a;
bool used[9];
void result() {
    set<int> check;
    for (string x : a) {
        string s = "";
        for (int i = 1; i <= k; i++) {
            s += x[sh[i] - 1];
        }
        check.insert(stoi(s));
    }
    res = min(res, *check.rbegin() - *check.begin());
}
void Try (int i) {
    for (int j = 1; j <= k; j++) {
        if (!used[j]) {
            used[j] = true;
            sh[i] = j;
            if (i == k) result();
            else Try(i + 1);
            used[j] = false;
        }
    }
}
int main() {
    int n;
    cin >> n >> k;
    sh[0] = 0;
    while(n--) {string x; cin >> x; a.push_back(x);}
    Try(1);
    cout << res;
}