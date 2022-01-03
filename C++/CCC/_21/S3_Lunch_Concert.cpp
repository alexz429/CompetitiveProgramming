#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // cout << "hi" << endl;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> linesweep;

    // cout << "hi" << endl;
    int n;
    cin >> n;
    ll rightSum = 0;
    ll leftSum = 0;
    ll wr = 0;
    ll wl = 0;
    for (int i = 0; i < n; i++) {
        int p, w, d;
        cin >> p >> w >> d;
        rightSum += (ll)max(0, p - d) * w;
        wr += w;
        linesweep.push({p - d, {0, w}});
        linesweep.push({p + d, {1, w}});
    }

    // cout << "hi" << endl;
    ll best = rightSum;
    // cout << rightSum << endl;
    int prev = 0;
    while (!linesweep.empty()) {
        auto next = linesweep.top();
        linesweep.pop();
        if (next.first >= 0) {
            rightSum -= (next.first - prev) * wr;
            leftSum += (next.first - prev) * wl;
            // cout << next.first << rightSum << leftSum << endl;
            prev = next.first;
            best = min(best, rightSum + leftSum);
        }
        if (next.second.first == 0) {
            wr -= next.second.second;
        } else {
            wl += next.second.second;
        }
    }
    cout << best << endl;
}