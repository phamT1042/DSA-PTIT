#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n;
        multiset<char> du0, du1, du2;
        int sum = 0;
        while(n--) {
            cin >> x; sum += x;
            if (x % 3 == 0) du0.insert(x + '0');
            else if (x % 3 == 1) du1.insert(x + '0');
            else du2.insert(x + '0');
        }
        string res = "";
        //Nếu tổng các chữ số chia 3 dư 1
        if (sum % 3 == 1) {
            //Xoá 1 chữ số dư 1 nhỏ nhất
            if (du1.size()) du1.erase(du1.begin());
            //Hoặc xoá 2 chữ số dư 2 nhỏ nhất
            else {
                du2.erase(du2.begin());
                du2.erase(du2.begin());
            }
        }
        //Nếu tổng các chữ số chia 3 dư 2
        else if (sum % 3 == 2) {
            //Xoá 1 chữ số dư 2 nhỏ nhất
            if (du2.size()) du2.erase(du2.begin());
            //Hoặc xoá 2 chữ số dư 1 nhỏ nhất
            else {
                du1.erase(du1.begin());
                du1.erase(du1.begin());
            }
        }
        for (char x : du0) res += x;
        for (char x : du1) res += x;
        for (char x : du2) res += x;
        sort(res.begin(), res.end(), greater<char>());
        if (res.length()) cout << res;
        else cout << -1;
        cout << '\n';
    }
}