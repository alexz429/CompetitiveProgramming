#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int c;
    cin >> c;
    int q;
    cin >> q;
    while (q--) {
        n -= c;
        cout << n << endl;
    }
}