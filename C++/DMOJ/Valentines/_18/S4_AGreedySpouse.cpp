#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    pair<int, int> arr1[n];
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        arr1[i] = {l, r};
    }
    sort(arr1, arr1 + n);
    vector<pair<int, int>> og;
    vector<pair<int, int>> disc;
    int prev = -100;
    for (int i = 0; i < n; i++) {
        if (arr1[i].first > prev) {
            prev = arr1[i].second;
            og.push_back(arr1[i]);
        } else {
            disc.push_back({arr1[i].second, arr1[i].first});
        }
    }

    int v[og.size()], d[og.size() - 1];
    sort(disc.begin(), disc.end());
    int sum = 0;
    for (int i = 0; i < og.size(); i++) {
        // cout << sum << endl;
        int tally = 0;
        int bot = (i == 0 ? 0 : og[i - 1].second);
        int top = (i == og.size() - 1 ? INT_MAX : og[i + 1].first);
        while (sum < disc.size() && disc[sum].second <= bot) sum++;
        while (sum < disc.size() && disc[sum].second > bot && disc[sum].first < top) {
            // cout << disc[sum].first << " " << disc[sum].second << endl;
            int end = disc[sum].first;
            sum++;
            while (sum < disc.size() && disc[sum].second <= end) sum++;
            tally++;
        }
        v[i] = tally;
        if (k == 2 && i < og.size() - 1) {
            int sum2 = sum;
            top = (i + 1 == og.size() - 1 ? INT_MAX : og[i + 2].first);
            while (sum2 < disc.size() && disc[sum2].second <= bot) sum2++;
            while (sum2 < disc.size() && disc[sum2].second > bot && disc[sum2].first < top) {
                int end = disc[sum2].first;
                sum2++;
                while (sum2 < disc.size() && disc[sum2].second <= end) sum2++;
                tally++;
            }
            d[i] = tally;
        }
    }
    int out = 0;
    for (int i = 0; i < og.size(); i++) {
        // cout << v[i] << endl;
        out = max(out, v[i]);
    }
    if (k == 1) {
        cout << og.size() + max(0, out - 1);
    } else {
        int m1 = 0, m2 = 0;
        for (int i = 0; i < og.size(); i++) {
            if (v[i] > m1) {
                m2 = m1;
                m1 = v[i];
            } else if (v[i] > m2) {
                m2 = v[i];
            }
        }
        int out2 = m1 + m2;
        for (int i = 0; i < og.size() - 1; i++) {
            out2 = max(out2, d[i]);
        }
        cout << og.size() + max(0, max(out - 1, out2 - 2)) << endl;
    }
}