#include<bits/stdc++.h>
using namespace std;
int n, s, a[31], res = 31;
int k = 1, chon[31];
void Try (int sum) {
    if (sum == s) {
        res = min(res, k - 1);
        return;
    }
    else if (sum > s) return;
    for (int j = chon[k - 1] + 1; j < n; j++) {
            chon[k++] = j;
            Try(sum + a[j]);
            k--;
    }
}
int main() {
    chon[0] = -1;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    Try(0);
    cout << res;
}
