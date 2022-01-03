#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[500001][3];

int main() {
    string in;
    cin >> in;
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 0; i < in.length(); i++) {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
        dp[i + 1][2] = dp[i][2];
        if (in[i] == 'L') {
            dp[i + 1][0]++;
        } else if (in[i] == 'M') {
            dp[i + 1][1]++;
        } else {
            dp[i + 1][2]++;
        }
    }
    int len = in.length();
    cout << (dp[dp[len][0] + dp[len][1]][2] + dp[dp[len][0]][1] + max(0, dp[dp[len][0]][2] - dp[len][0] + dp[dp[len][0] + dp[len][1]][0])) << endl;
}