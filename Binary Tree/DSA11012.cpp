#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n1, n2, x, y;
        char z;
        vector<string> tree1, tree2;
        string s;
        cin >> n1;
        for (int i = 0; i < n1; i++) {
            cin >> x >> y >> z;
            s = to_string(x) + to_string(y) + string(1, z);
            tree1.push_back(s);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++) {
            cin >> x >> y >> z;
            s = to_string(x) + to_string(y) + string(1, z);
            tree2.push_back(s);
        }
        if (n1 != n2) cout << 0 << '\n';
        else {
            sort(tree1.begin(), tree1.end());
            sort(tree2.begin(), tree2.end());
            int flag = 1;
            for (int i = 0; i < n1; i++) {
                if (tree1[i] != tree2[i]) {
                    flag = 0;
                    break;
                }
            }
            cout << flag << '\n';
        }
    }
    return 0;
}