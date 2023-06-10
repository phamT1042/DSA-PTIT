#include <bits/stdc++.h>
using namespace std;
int cnt, flag; //cnt là số số hạng trong cách phân tích hiện tại
               //VD: (3, 1): 2 - (1, 1, 1, 1): 4 -...
void phanTich(int a[]) {
    int i = cnt;
    while (i > 0 && a[i] == 1) i--; //Tìm vị trí i có a[i] > 1 để giảm và phân tích tiếp
    if (!i) { //Cấu hình cuối gồm toàn 1
        flag = 1;
        return;
    }
    a[i]--; //Giảm 1 đơn vị tại ví trí i
    int number_of_digits_1 = cnt - i; //Số chữ số 1 đã chạy qua đứng sau vị trí i
                                      //VD: (3 1): 1 - (2 1 1): 2 - ...
    number_of_digits_1++; //Tăng các chữ số 1 đằng sau lên 1 vì đã giảm của a[i]
    cnt = i; //Đặt số số hạng của cách phân tích tại vị trí i, chuẩn bị phân tích đằng sau i
    int q = number_of_digits_1 / a[i];
    int r = number_of_digits_1 % a[i]; 
    while (q--) 
        a[++cnt] = a[i];
    if (r) 
        a[++cnt] = r;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n + 1];
        cnt = 1; a[1] = n;
        flag = 0;
        while (!flag) {
            string s = "(";
            for (int i = 1; i <= cnt; i++) 
                s += to_string(a[i]) + " ";
            s.erase(s.length() - 1, 1);
            s += ")";
            cout << s << ' ';
            phanTich(a);
        }
        cout << '\n';
    }
    return 0;
}