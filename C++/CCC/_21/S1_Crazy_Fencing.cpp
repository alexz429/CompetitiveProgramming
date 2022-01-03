#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int in[10001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        cin >> in[i];
    }
    double out = 0;
    for (int i = 0; i < n; i++) {
        double next;
        cin >> next;
        out += next * min(in[i], in[i + 1]) + next / 2 * (double)abs(in[i] - in[i + 1]);
    }
    cout << fixed << out << endl;
}