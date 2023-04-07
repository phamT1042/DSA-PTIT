#include<bits/stdc++.h>
using namespace std;
vector<string> name, res;
int n, sh[11], used[11];
void in() {
    string s = "";
    for (int i = 0; i < n; i++) {
        s += name[sh[i]] + " ";
    }
    res.push_back(s);
}
void Try (int i) {
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            sh[i] = j;
            used[j] = 1;
            if (i == n - 2) in();
            else Try (i + 1);
            used[j] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        name.push_back(x);
    }
    string last; cin >> last;
    for (int i = 0; i < n; i++) {
        if (last == name[i]) {
            sh[n - 1] = i;
            used[i] = 1;
            break;
        }
    }
    Try(0);
    sort(res.begin(), res.end());
    for (string x : res) cout << x << '\n';
}
