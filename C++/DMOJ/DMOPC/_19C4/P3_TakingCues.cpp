#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int months[10000][4];
ll dp[10000][101];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>months[i][0]>>months[i][1]>>months[i][2]>>months[i][3];
    }
    for(int i=0;i<=100;i++){
        dp[n-1][i] = months[n-1][3]*min(i, months[n-1][1]);
    }
    // cout<<"Start DP"<<endl;
    for(int i=n-2;i>=0;i--){
        // cout<<i<<endl;
        for(int j=0;j<=100;j++){
            // cout<<i<<endl;
            ll best = 0;
            bool trade = false;
            if(months[i][2]<months[i][3]){
                trade = true;
            }
            for(int l= max(0,j-months[i][1]); l<=min(100,j+months[i][0]);l++){
                // cout<<l<<" ";
                ll base = dp[i+1][l] - l*m;
               if(trade){
                int left = max(0,max(j-months[i][1], l-months[i][0]));
                base+= max(0,j-left)*months[i][3] - max(0,l-left)*months[i][2];
               }
               else{
                   if(l<j){
                    base+=(j-l)*months[i][3];
                }
                else if(l>j){
                    base-=(l-j)*months[i][2];
                }
               }
               best = max(best,base);
            }
            dp[i][j] = best;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=20;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][0]<<endl;
}