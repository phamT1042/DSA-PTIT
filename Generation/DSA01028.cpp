#include<bits/stdc++.h>
using namespace std;
int sh[11], flag = 0;
void sinhTH (vector<int> a, int n, int k) {
    for (int i = 0; i < k; i++) {
        cout << a[sh[i] - 1] << ' ';
    }
    cout << endl;
    int i = k - 1;
    while (i >= 0 && sh[i] == n - k + i + 1) i--;
    if (i == -1) {
        flag = 1;
        return;
    }
    sh[i]++;
    for (int j = i + 1; j < k; j++) sh[j] = sh[j - 1] + 1;
}
int main () {
    int n, k, x; cin >> n >> k;
    vector<int> a;
    set<int> pt;
    for (int i = 0; i < n; i++) {
        cin >> x; 
        pt.insert(x);
    }
    for (int i = 0; i < k; i++) sh[i] = i + 1;
    for (int x : pt) a.push_back(x);
    while (!flag)
        sinhTH(a, a.size(), k);
    return 0;
}
