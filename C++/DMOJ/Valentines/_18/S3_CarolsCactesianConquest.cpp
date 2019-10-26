#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,K;
ll dp[101][101][101];
int main(){
//TODO : add PSA

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;
    dp[0][0][0]=1;
    for(int n=1;n<=N;n++){
        for(int k=1;k<=K;k++){
            for(int j=1;j<=N;j++){
                // dp[n][k][j] += dp[n-1][k-1][j];
            }
        }
    }
}