#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        stack<char> ngoac;
        int open = 0, close = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') ngoac.push(s[i]);
            else {
                if (!ngoac.empty()) ngoac.pop();
                else close++;
            }
        }
        while (!ngoac.empty()) {
            ngoac.pop();
            open++;
        }
        //Nếu dãy chỉ còn lại toàn ngoặc đóng hoặc toàn ngoặc mở, ta chỉ cần đổi chiều của 1/2 số ngoặc
        if (open == 0 || close == 0) cout << max(close, open) / 2;
        else {
            //Nếu dãy có cả ngoặc đóng và mở, chỉ có thể là có close số ngoặc đóng bên trái và
            //open số ngoặc mở bên phải. Ta khử các ngoặc đóng và mở đầu tiên bằng cách đổi chiều 1/2 số ngoặc đóng (khử các ngoặc đóng) 
            //và 1/2 số ngoặc mở (khử các ngoặc mở).
            int deleteOpen = open / 2, deleteClose = close / 2;
            int change = deleteOpen + deleteClose;
            open -= deleteOpen * 2;
            close -= deleteClose * 2;
            //Đến cuối nếu ngoặc mở và đóng vẫn còn, điều đó chỉ đúng khi số ngoặc mở = số ngoặc đóng
            //còn lại là 1, ta đổi chiều cả 2 ngoặc này là xong
            if (open) change += 2;
            cout << change;
        }
        cout << "\n";
    }
}