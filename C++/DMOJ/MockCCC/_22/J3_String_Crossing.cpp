#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tally[26][2];

int main() {
    fill(&tally[0][0], &tally[25][2], 0);
    int l, t;
    string L, T;
    cin >> l >> t >> L >> T;
    for (int i = 0; i < l; i++) {
        tally[L[i] - 'A'][0]++;
    }
    for (int i = 0; i < t; i++) {
        tally[T[i] - 'A'][1]++;
    }
    ll out = 0;
    for (int i = 0; i < 26; i++) {
        out += tally[i][0] * tally[i][1];
    }
    ll small = 10000000;
    ll big = 0;
    for (int i = 0; i < 26; i++) {
        if (tally[i][1] > 0) {
            small = min(small, tally[i][0]);
        }
        big = max(big, tally[i][0]);
    }
    out += big - small;
    cout << out << endl;
}