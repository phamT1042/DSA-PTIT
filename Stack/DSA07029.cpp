#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s, add, solve; cin >> s;
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') continue;
            //Nếu là [, lấy số đằng trước nó nếu có + [ add vào stack
            else if (s[i] == '[') {
                add = "";
                //Có thể không có số trước [
                if (i - 1 < 0) {
                    add += "1";
                    add += s[i];
                    st.push(add);
                }
                else if (s[i - 1] < '0' || s[i - 1] > '9') {
                    add += "1";
                    add += s[i];
                    st.push(add);
                }
                else {
                    //Số trước [ có thể có lớn hơn 1 chữ số
                    for (int j = i - 1; j >= 0; j--) {
                        if (s[j] < '0' || s[j] > '9') break;
                        add = s[j] + add;
                    }
                    add += s[i];
                    st.push(add);
                }
            }
            //Nếu là chữ cái, add cả dãy chữ cái
            else if (s[i] >= 'a' && s[i] <= 'z') {
                add = "";
                while (s[i] >= 'a' && s[i] <= 'z') {
                    add += s[i++];
                    if (i == s.length()) break;
                }
                i--;
                st.push(add);
            }
            //Nếu là đóng ngoặc
            else {
                add = "";
                while (1) {
                    //Lấy các dãy chữ cái trong stack đến khi gặp [ thì dừng lại
                    if (st.top()[st.top().length() - 1] == '[') break;
                    add = st.top() + add;
                    st.pop();
                }
                //Số lần lặp dãy chữ cái vừa lấy ra bằng số trước [
                string numberLoop = st.top().substr(0, st.top().length() - 1);
                int loop = stoi(numberLoop);
                st.pop();
                solve = "";
                while (loop--) solve += add;
                st.push(solve);
            }
        }
        string res = "";
        while (st.size()) {
            res = st.top() + res;
            st.pop();
        }
        cout << res << '\n';
    }
    return 0;
}