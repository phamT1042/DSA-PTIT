#include<bits/stdc++.h>
using namespace std;
bool check (string s) {
    if (s.length() < 2) return false;
    int cnt = 0;
    for (char x : s) {
        if (x == '(') cnt++;
        else if (x == ')') cnt--;
        if (cnt < 0) return false;
    }
    return !cnt;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        queue<string> del;   //Lưu các cách xoá ngoặc
        map<string, int> xetDayNgoac; //Kiểm tra cách xoá ngoặc này liệu đã tồn tại ?
        set<string> res;   
        del.push({s, 0});
        int loaiBo = 0;    //đánh dấu khi 1 phép xoá các dấu ngoặc ít nhất tạo biểu thức đúng xuất hiện
        while (del.size()) {
            string tmp = del.front(); del.pop();
            if (check(tmp)) {
                loaiBo = 1;         //xuất hiện biểu thức đúng
                res.insert(tmp);
            }
            if (loaiBo) continue;
            for (int i = 0; i < tmp.length(); i++) {
                if (tmp[i] != '(' && tmp[i] != ')') continue;
                string xoa = tmp.substr(0, i) + tmp.substr(i + 1);
                if (!xetDayNgoac[xoa]) {
                    del.push(xoa);
                    xetDayNgoac[xoa] = 1;
                }
            }
        }
        if (!loaiBo) cout << -1;
        else for (string x : res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}