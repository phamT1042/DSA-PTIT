#include<bits/stdc++.h>
using namespace std;
vector<string> name, a;
int sh[40];
int k;
void result() {
    for (int i = 1; i <= k; i++) {
        cout << name[sh[i] - 1] << ' ';
    }
    cout << endl;
}
void Try (int i) {
    for (int j = sh[i - 1] + 1; j <= name.size() - k + i; j++) {
        sh[i] = j;
        if (i == k) result();
        else Try(i + 1);
    }
}
int main() {
    int n; cin >> n >> k;
    set<string> nameIN;
    while (n--) {
        string s; cin >> s;
        nameIN.insert(s);
    }
    for (string x : nameIN) name.push_back(x);
    Try(1);
}