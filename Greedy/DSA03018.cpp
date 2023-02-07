#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int number4, number7 = n / 7;
        while (number7 >= 0) {
            int du = n - number7 * 7;
            if (du % 4 == 0) {
                number4 = du / 4;
                break;
            }
            number7--;
        }
        if (number7 >= 0) {
            while (number4--) cout << "4";
            while (number7--) cout << "7";
            cout << "\n";
        }
        else cout << "-1\n";
    }
	return 0;
}