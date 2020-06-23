#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[5001][5001];// dp[n][p] = number of people needed to get p points with first n prov

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<5001;i++){
        dp[0][i] = (ll)1e15;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    int PointSum = 0;
    for(int i=1;i<=n;i++){
        int a,b;
        
        cin>>a>>b;
        PointSum+=b;
        for(int j=0;j<=5000;j++){
            if(j<b){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-b]+a/2+1);
        }
    }
    ll best = (ll)1e15;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=15;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=PointSum/2+1;i<=PointSum;i++){
        if(dp[n][i]!=1e15){
            cout<<dp[n][i]<<endl;
            return 0;
        }
    }// cout<<best<<"\n";

}