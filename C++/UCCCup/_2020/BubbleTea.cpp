#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5001];
ll vals[5001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>vals[i];
    }
    dp[1] = vals[1];
    if(n==1){
        cout<<dp[1];
        return 0;
    }
    dp[2] = (vals[1]+vals[2]-0.25*min(vals[1], vals[2]));
    if(n==2){
        cout<<dp[2];
        return 0;
    }
    for(int i=3;i<=n;i++){
        int a = vals[i]+dp[i-1];
        int b = vals[i]+vals[i-1]-(int)(0.25*min(vals[i], vals[i-1]))+dp[i-2];
        int c = vals[i]+vals[i-1]+vals[i-2]-(int)(0.5*min(vals[i], min(vals[i-1], vals[i-2])))+dp[i-3];
        dp[i] = min(a,min(b,c));

    }
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<endl;
    }
    cout<<dp[n]<<endl;
}