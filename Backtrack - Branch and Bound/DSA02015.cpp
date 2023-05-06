#include<bits/stdc++.h>
using namespace std;
bool check (string s) {
    if (s == "") return false;  //rỗng
    if (s.length() == 1 && s[0] != '(' && s[0] != ')') return false; //chỉ 1 kí tự và nó không phải ngoặc
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
        int loaiBo = 0;    //lưu số phép loại bỏ ít nhất để được 1 dãy ngoặc đúng
        while (del.size()) {
            string tmp = del.front(); del.pop();
            if (check(tmp)) {
                loaiBo = 1;
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
        else for (string s : res) cout << s << ' ';
        cout << '\n';
    }
    return 0;
}