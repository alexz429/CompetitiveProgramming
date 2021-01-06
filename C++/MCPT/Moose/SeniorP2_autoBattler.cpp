#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long dp[3001][3001];

long recurse(int size, int tier){
    if(dp[size][tier]!=0){
        return dp[size][tier];
    }
    int cost=0;
    for(int i=1;i<=size;i++){
        cost += recurse(i,tier-1);
        cost%=(long)1e9+7;
    }
    return dp[size][tier]= cost;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    for(int i=1;i<3000;i++){
        dp[i][1] =i;
    }
    int n,k;
    cin>>n>>k;
    cout<<recurse(n,k)<<endl;
} 