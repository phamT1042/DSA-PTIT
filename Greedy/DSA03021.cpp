#include<bits/stdc++.h>
using namespace std;
int b[1001];
bool check (int k, int a[], int n) {
    int flag;
    for (int i = 0; i < n; i++) {
        flag = 0;
        int h = (a[i] / k) - k; //tìm hmin để a[i] / h = k
        if (h <= 0) h = 1;
        for (h; h <= a[i] / k; h++) {
            if (a[i] / h == k) {
                flag = 1;
                break;
            }
        }
        if (flag) b[i] = h;   //b[i]min = hmin
        else return false;
    }
    return true;
}
int main() {
    int n; cin >> n;
    int a[n], res = INT_MAX, sum; 
    for (int &x : a) cin >> x;
    int Min = *min_element(a, a + n);
    for (int k = Min; k >= 1; k--) { //chạy k là các giá trị thương có thể có
                                    //có của a[i]/b[i] = a[i+1]/b[i+1] = ... = k
        if (check(k, a, n)) {
            sum = 0;
            for (int i = 0; i < n; i++) sum += b[i];
            res = min (sum, res);
        }
    }
    cout << res;
}