#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    while(true){
        
int m,n;

    cin>>m>>n;
    if(m==0&&n==0)return 0;
    int val[m][n];
    int dp[m][n];
    fill(&dp[0][0], &dp[m][n], -1);
    for(int i=0;i<m;i++){
        string next;
        cin>>next;
        for(int j=0;j<n;j++){
            if(next[j]=='.'){
                val[i][j] = 0;
            }
            else if(next[j]=='*'){
                val[i][j] = -1;
            }
            else{
                val[i][j] = next[j]-'0';
            }
        }
    }
    queue<pair<int,int>> starts;
    starts.push({m-1,0});
    for(int i=0;i<n;i++){
        int lim = starts.size();
        for(int j=0;j<lim;j++){
            pair<int,int> next= starts.front();
            // cout<<next.first<<" "<<next.second<<endl;
            starts.pop();
            if(val[next.first][i]==-1)continue;
            int tally = next.second+val[next.first][i];
            dp[next.first][i] = max(dp[next.first][i],tally);
            for(int k = next.first-1;k>=0;k--){
                if(val[k][i]==-1)break;
                tally+=val[k][i];
                dp[k][i] = max(dp[k][i],tally);
            }
            
            tally = next.second+val[next.first][i];
            for(int k=next.first+1;k<m;k++){
                if(val[k][i]==-1)break;
                
                tally+=val[k][i];

                // cout<<k<<" "<<i<<" "<<tally<<" "<<dp[k][i]<<endl;
                dp[k][i] = max(dp[k][i],tally);    
            }
        }
        for(int j=0;j<m;j++){
            if(val[j][i]!=-1&&dp[j][i]!=-1){
                starts.push({j, dp[j][i]});
            }
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[m-1][n-1]<<"\n";
    }
    
}