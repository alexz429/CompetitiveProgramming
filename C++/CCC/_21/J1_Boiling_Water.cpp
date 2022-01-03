#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int b;
    cin >> b;
    b = b * 5 - 400;
    cout << b << endl;
    if (b < 100) {
        cout << 1 << endl;
    } else if (b == 100) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }
}