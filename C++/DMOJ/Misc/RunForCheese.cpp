#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<int> pos;
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        pos.push_back(next);
    }
    sort(pos.begin(), pos.end());
    // for(int next:pos){
    //     cout<<next<<" ";
    // }
    // cout<<endl;
    ll dp[n][n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            // if(pos[j]>m||pos[j+i]<m){
            //     dp[j][j+i][0] = 1e9;
            //     dp[j][j+i][1] = 1e9;
            //     continue;
            // }
            if(i==0){
                dp[j][j][0]=abs(pos[j]-m)*n;
                dp[j][j][1]=abs(pos[j]-m)*n;
                continue;
            }
            dp[j][j+i][0] = min(dp[j+1][j+i][0] + (pos[j+1]-pos[j])*(n-i), dp[j+1][j+i][1]+(pos[j+i]-pos[j])*(n-i));
            dp[j][j+i][1] = min(dp[j][j+i-1][0] + (pos[j+i]-pos[j])*(n-i), dp[j][j+i-1][1]+(pos[j+i]-pos[j+i-1])*(n-i));
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         cout<<min(dp[i][j][0], dp[i][j][1])<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<min(dp[0][n-1][0], dp[0][n-1][1])<<endl;


}