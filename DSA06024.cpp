#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    for (int i = 0; i < n - 1; i++) {
        cout << "Buoc " << i + 1 << ": ";
        int minPos = i, min = a[i];
        for (int j = i + 1; j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                minPos = j;
            }
        }
        swap(a[i], a[minPos]);
        for (int k = 0; k < n; k++) cout << a[k] << ' ';
        cout << endl;
    }
	return 0;
}