#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1000001];


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
      int next;cin>>next;
      if(next==1){
        dp[i] = i;
      }  
      else{
        dp[i] = dp[i-1];
      }
    }
    int q;cin>>q;
    while(q--){
        int l, r;cin>>l>>r;
        // cout<<"->"<<dp[r]<<" ";
        if(dp[r]<l){
            cout<<(int)((r-l+1)%2==0)<<endl;
        }
        else if(dp[r]==l){
            cout<<(int)((r-dp[r])%2==0)<<endl;
        }
        else{
            cout<<(int)((r-dp[r]+1)%2==0)<<endl;
        }
    }
}