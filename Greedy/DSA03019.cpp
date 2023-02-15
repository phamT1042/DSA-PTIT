#include<bits/stdc++.h>
using namespace std;
long long gcd (long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    int t; cin >> t;
    while (t--) {
        //Xuất phát từ phân số đơn vị lớn nhất là 1/1; giảm dần xuống 1/2; 1/3;...
        //và lấy p/q trừ đi nó nếu p/q > 1/i. Lặp đến khi p = 1, in ra p/q cuối
        long long p, q; cin >> p >> q;
        long long toiGian = gcd(p, q);
        p /= toiGian; q /= toiGian;
        for (long long i = 1; i <= LONG_LONG_MAX; i++) {
            if (p == 1) {
                cout << p << "/" << q << endl;
                break;
            }
            if (p * i > q) {//p/q > 1/i
                cout << "1/" << i << " + ";
                p = p * i - q; //p/q - 1/i
                q *= i;  
                toiGian = gcd(p, q);
                p /= toiGian; q /= toiGian;
            }
        }
    }
}