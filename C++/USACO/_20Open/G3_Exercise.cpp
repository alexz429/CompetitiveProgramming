#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e4 + 4;
int n,m; vector<int> p; ll dp[MM], ans; bool f[MM];
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        if(!f[i]){
            p.push_back(i);
            for(int j=2*i;j<=n;j+=i)f[j] = 1;
        }
    }
    dp[0] = 1;
    for(int i=0;i<p.size();i++){
        for(int j=n;j>=p[i];j--){
            for(int t=p[i];t<=j;t*=p[i])
                dp[j] = (dp[j]+dp[j-t]*t)%m;
        }
    }
    for(int i=0;i<=n;i++) ans = (ans+dp[i])%m;
    cout<<ans<<"\n";
}