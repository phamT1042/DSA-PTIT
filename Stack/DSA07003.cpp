#include<bits/stdc++.h>
using namespace std;
string check(vector<char> kt) {
    stack<char> res;
    for (char x : kt) {
        if (x != ')') res.push(x); //chưa gặp dấu đóng ngoặc thì cứ push vào stack
        else {
            //khi gặp dấu đóng ngoặc, chạy về trước cho đến khi gặp dấu mở ngoặc
            //loại bỏ tất cả các dấu +, -, * và / trên đường tìm kiếm, loại bỏ luôn mở ngoặc
            //Sẽ dư dấu ngoặc khi giữa 2 dấu mở và đóng không có dấu phép tính nào (flag = 0)
            char sign = res.top(); 
            if (sign == '(') return "Yes";
            while (sign != '(') {
                res.pop();
                sign = res.top();
            }
            res.pop();
        }  
    }
    return "No";
}
int main() {
    int t; cin >> t;
    cin.ignore();
    while (t--) {
        string s; getline(cin, s);
        vector<char> kt;
        for (char x : s) 
            if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')') 
                kt.push_back(x);
        cout << check(kt) << endl;
    }
}