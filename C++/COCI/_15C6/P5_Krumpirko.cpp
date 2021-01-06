#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[2][101][10001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,l;
    cin>>n>>l;
    int pots[n];
    int nums[n];
    int totalPots=0;
    int totalCost=0;
    for(int i=0;i<n;i++){
        cin>>pots[i];
        totalPots+=pots[i];
    }
    for(int i=0;i<n;i++){
        cin>>nums[i];
        totalCost+=nums[i];
    }
    int temp=0;
    int flip=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<101;j++){
            for(int k=0;k<10001;k++){
                if(k==0&&j==0){
                    dp[i][j][k]=0;
                }   
                else{
                    dp[i][j][k]=1000000000;
                }
                
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        // cout<<i<<endl;
        temp+=pots[i-1];
        
        for(int j=1;j<=i;j++){
            for(int k=1;k<=temp;k++){
                int best = dp[flip^1][j][k];
                // cout<<k<<endl;
                if(k-pots[i-1]>=0&&(k-pots[i-1]==0||dp[flip^1][j-1][k-pots[i-1]]!=1000000000)){
                    best = min(best, dp[flip^1][j-1][k-pots[i-1]] + nums[i-1]);
                }
                dp[flip][j][k] = best;
                // cout<<dp[flip][j][k]<<" ";
            }
            // cout<<endl;
        }
        flip^=1;
    }
    // cout<<"done"<<endl;
    double ans = -1;
    for(int i=1;i<totalPots;i++){
        
        if(dp[flip^1][l][i]==1000000000)continue;
        double nextVal = (double)dp[flip^1][l][i]/(double)i*(double)(totalCost-dp[flip^1][l][i])/(double)(totalPots-i);
        
        // cout<<i<<" "<<dp[flip^1][l][i]<<" "<<nextVal<<endl;
        
        if(ans==-1){
            ans = nextVal; 
        }
        else{
            ans = min(ans,nextVal);
        }
    }
    cout<<fixed<<setprecision(3)<<ans<<endl;
}