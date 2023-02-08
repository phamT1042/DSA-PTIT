#include <bits/stdc++.h>
using namespace std;
int sh[11], res, flag;
void result(int k, int s) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += sh[i];
    }
    if (sum == s) res++;
}
void sinhTH(int n, int k, int s) {
    result(k, s);
    int i = k - 1;
    while (i >= 0 && sh[i] == n - k + i + 1) i--;
    if (i == -1) {
        flag = 1;
        return;
    }
    sh[i]++;
    for (int j = i + 1; j < k; j++) sh[j] = sh[j - 1] + 1;
}
int main() {
    int n, k, s;
    while (1) {
        cin >> n >> k >> s;
        if (!n && !k && !s) break;
        res = 0, flag = 0;
        if (k <= n) {
            for (int i = 0; i < k; i++) sh[i] = i + 1;
            while (!flag) {
                sinhTH(n, k, s);
            }
        }
        cout << res << endl;
    }
    return 0;
}