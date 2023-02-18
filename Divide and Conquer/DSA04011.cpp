#include<bits/stdc++.h>
using namespace std;
string nhanSNL (string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> cal(a.length() + b.length());
    for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++)
			cal[i + j] = cal[i + j] + (a[i] - '0') * (b[j] - '0');
	}
	string res = "";
	for (int i = 0; i < cal.size(); i++) {
		int du = cal[i] % 10;
		int nho = cal[i] / 10;
		if (i + 1 < cal.size()) {
			cal[i + 1] += nho;
		}
		res = to_string(du) + res;
	}
	while (res[0] == '0') res.erase(0, 1);
	if (res.length() == 0) return "0";
	return res;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        long long a = 0, b = 0;
        int mu = 1;
        for (int i = s1.length() - 1; i >= 0; i--) {
            a += (s1[i] - '0') * mu;
            mu *= 2;
        }
        mu = 1;
        for (int i = s2.length() - 1; i >= 0; i--) {
            b += (s2[i] - '0') * mu;
            mu *= 2;
        }
        cout << nhanSNL(to_string(a), to_string(b)) << endl;
    }
}