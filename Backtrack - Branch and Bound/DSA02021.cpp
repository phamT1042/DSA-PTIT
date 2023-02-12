#include<bits/stdc++.h>
using namespace std;
string s;
int Try (long long i, long long n) {
    if (i <= s.length()) {
        if (i == 0) return s.length() - 1;
        return i - 1;
    }
    //Nếu vị trí i là n => là vị trí n/2 của xâu đảo với xâu n/2
    //=> là vị trí n/2 - 1 của xâu n/2
    if (i == n) return Try (n / 2 - 1, n / 2);
    //Nếu vị trí i nằm trong khoảng n đến n/2 => i nằm ở vị trí i - n/2
    //của xâu đảo với xâu n/2 => vị trí i - n/2 - 1 của xâu n/2
    if (i < n && i > n / 2) return Try (i - n / 2 - 1, n / 2);
    //Nếu vị trí i nhỏ hơn n / 2 => giảm n đến TH trong khoảng (n/2, n)
    return Try (i, n / 2);
}
int main() {
    int t; cin >> t;
    while (t--) {
        long long i;
        cin >> s >> i;
        long long n = s.length();
        while (n < i) n *= 2; //Xây dựng các xâu độ dài: 2n, 4n, 8n,...
                              //Ta được xâu cuối có độ dài m sao cho i = m hoặc i < m (m = (2^x)n)
        cout << s[Try(i, n)] << endl;
    }
}