#include<bits/stdc++.h>
using namespace std;
void quickSort(int a[], int left, int right) {
    int x = a[(left + right) / 2];
    int i = left, j = right;
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i++], a[j--]);
        }
    } while (i < j);
    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        quickSort(a, 0, n - 1);
        vector<int> s (a, a + n / 2);
        vector<int> e (a + n / 2, a + n);
        reverse(e.begin(), e.end());
        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) cout << e[j++] << ' ';
            else cout << s[k++] << ' ';
        }
        cout << endl;
    }
}