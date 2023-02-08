#include<bits/stdc++.h>
using namespace std;
int n, a[11], cot[11], xuoi[21], nguoc[21], res;
void Try (int i) {
    for (int j = 0; j < n; j++) {
        if (!cot[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]) {
            a[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[j + i - 1] = 1;
            if (i == n - 1) res++;
            else Try(i + 1);
            cot[j] = xuoi[i - j + n] = nguoc[j + i - 1] = 0;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        res = 0;
        memset(xuoi, 0, sizeof(xuoi));
        memset(nguoc, 0, sizeof(nguoc));
        memset(cot, 0, sizeof(cot));
        Try(0);
        cout << res << endl;
    }
}