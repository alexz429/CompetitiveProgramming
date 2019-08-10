#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int N, K, pos[202][MM], cur, pre, now = 1, q[MM], f, r; ll dp[2][MM], psa[MM], ans = -1;
double slope(int p, int q){
    if(psa[p] == psa[q]) return -1.0e18;
    return (double)(dp[pre][p] - psa[p]*psa[N] - dp[pre][q] + psa[q]*psa[N])/(double)(psa[q] - psa[p]);
}
int main(){
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++) { scanf("%lld", &psa[i]); psa[i] += psa[i-1]; }
    for(int k=1; k<=K; k++){
        memset(dp[now], -1, sizeof(dp[now]));
        f = r = 1;
        for(int i=1; i<=N; i++){
            while(f < r && slope(q[f], q[f+1]) <= psa[i]) f++;
            dp[now][i] = dp[pre][q[f]] + (psa[i] - psa[q[f]])*(psa[N] - psa[i]);
            pos[k][i] = q[f];
            printf("%d ", dp[now][i]);
            while(f < r && slope(q[r-1], q[r]) >= slope(q[r], i) ) r--;
            q[++r] = i;
        }
        printf("\n");
        pre^=1; now^=1;
    }
    for(int i=1; i<=N; i++)
        if(dp[pre][i] > ans){ ans = dp[pre][i]; cur = i; }
    printf("%lld\n", ans);
    for(int i=K; i>=1; i--){
        printf("%d ", cur); cur = pos[i][cur];
    }
}