#include<bits/stdc++.h>
using namespace std;
void thapHN(int n, char a, char b, char c) {
    if (n == 1) { 
        cout << a << " -> " << c << endl;
        return;
    }
    thapHN(n - 1, a, c, b); //Chuyển n - 1 đĩa từ cột a sang b lấy c làm trung gian
    thapHN(1, a, b, c); //Chuyển đĩa cuối từ cột a sang c lấy cột b làm trung gian
    thapHN(n - 1, b, a, c); //Chuyển n - 1 đĩa từ cột b sang c lấy a làm trung gian
}
int main() {
    int n; cin >> n;
    thapHN(n, 'A', 'B', 'C');
}