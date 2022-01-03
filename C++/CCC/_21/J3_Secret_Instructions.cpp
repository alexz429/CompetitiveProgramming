#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string com;
    while (n != 99999) {
        int a = (n % 10000) / 1000 + n / 10000;
        int b = n % 1000;
        if (a != 0) {
            if (a % 2 == 0)
                com = "right";
            else
                com = "left";
        }
        cout << com << " " << b << endl;
        cin >> n;
    }
}