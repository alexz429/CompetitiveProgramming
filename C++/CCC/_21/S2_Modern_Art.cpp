#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> rows(n);
    vector<bool> cols(m);
    fill(rows.begin(), rows.end(), 0);
    fill(cols.begin(), cols.end(), 0);
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        int ind;
        cin >> ind;
        if (c == 'R') {
            rows[ind - 1] = !rows[ind - 1];
        } else {
            cols[ind - 1] = !cols[ind - 1];
        }
    }
    int out = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << (rows[i] + cols[j]) % 2;
            if (rows[i] ^ cols[j]) out++;
        }
        // cout << endl;
    }
    cout << out << endl;
}