#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; string s; cin >> n >> s;
    vector<int> s1, s2;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'T') {
            s1.push_back(2);
            s2.push_back(2);
        }
        else if (s[i] == 'X') {
            s1.push_back(1);
            s2.push_back(1);
        }
        else {
            s1.push_back(3);
            s2.push_back(3);
        }
    }
    sort(s2.begin(), s2.end());
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s1[i] != s2[i]) {
            int j = i + 1;
            int save;
            for (j; j < n; j++) {
                if (s1[j] == s2[i]) {
                    save = j;
                    if (s2[j] == s1[i]) {
                        save = j;
                        break;
                    }
                }
            }
            swap(s1[save], s1[i]);
            res++;
        }
    }
    cout << res;
}