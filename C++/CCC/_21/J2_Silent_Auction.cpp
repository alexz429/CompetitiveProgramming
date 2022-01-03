#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string name;
    int val = -1;
    for (int i = 0; i < n; i++) {
        string nextName;
        int nextVal;
        cin >> nextName >> nextVal;
        if (nextVal > val) {
            name = nextName;
            val = nextVal;
        }
    }
    cout << name << endl;
}