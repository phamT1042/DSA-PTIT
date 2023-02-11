#include<bits/stdc++.h>
using namespace std;
int n, k, a[15], pre[15], sum_con, res = 0, day_con;
//day_con: đếm số dãy con tạo được, check bằng k
void Try (int i) {
    //Nếu đã xây dựng được day_con dãy con
    if (day_con == k) {
        //Kiểm tra xem đã chạm đến cuối phải mảng chưa
        //(Vì gọi chỉ số tiếp theo (Try(j + 1)) nên ở chỉ số n cuối nó gọi đến chỉ số n + 1)
        if (i == n + 1) res++;
        return;
    }
    for (int j = i; j <= n; j++) {
        //Xây dựng dãy con có tổng là sum_con trong [i, j]
        if (pre[j] - pre[i] + a[i] == sum_con) {//
            day_con++; 
            //Xây dựng dãy con tiếp trong [j + 1,...]
            Try (j + 1); 
            day_con--;
        }
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    if (abs(pre[n]) % k != 0) cout << "0";
    else {
        day_con = 0;
        sum_con = pre[n] / k;
        Try(1);
        cout << res;
    }
}