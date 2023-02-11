#include<bits/stdc++.h>
using namespace std;
int chon[40], S, t[40], n, sum, res = 40;
//chon[i]: chon[i] = j tức chọn tờ tiền tại vị trí j của mảng t (j = 1, n)
//res: số tờ tiền ít nhất cần tìm
void Try (int k) {
    if (sum == S) {
        res = min(res, k - 1);
        return;
    }
    else if (sum > S) return;
    for (int j = chon[k - 1] + 1; j <= n; j++) {
        sum += t[j];
        chon[k] = j;
        Try(k + 1);
        sum -= t[j];
    }
}
int main() {
    cin >> n >> S;        
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        chon[i] = 0;
    }
    sort(t + 1, t + n + 1, greater<int>());
    int k = 1; //k: số tờ tiền chọn từ cách chon[] nào đấy
    sum = 0;
    Try(k);
    if (res != 40) cout << res;
    else cout << "-1";
}