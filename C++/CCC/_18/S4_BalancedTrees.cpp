#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp1[100000];
ll dp2[100000];
int big;
ll dynamic(int n){
    if(n>sqrt(big)){
        return dp2[big/n];
    }
    else{
        return dp1[n];
    }
}
ll insert(int n, ll val){
    if(n>sqrt(big)){
        dp2[big/n] = val;
    }
    else{
        dp1[n] = val;
    }
    return val;
}
ll recurse(int n){
    // cout<<n<<"start"<<endl;
    if(dynamic(n)!=0) return dynamic(n);
    ll tally = 0;
    int branches = 2;
    int prevweight = -1;
    for(;prevweight!=n/branches&&branches<=n;branches++){
        tally += recurse(n/branches);
        prevweight = n/branches;
    }
    if(branches>n){
        return insert(n, tally);
    }
    // cout<<n<<"mid"<<prevweight<<endl;
    tally += recurse(prevweight)*(n/prevweight-n/(prevweight+1)-1);
    for(prevweight--;prevweight>=1;prevweight--){
        tally += recurse(prevweight)*(n/prevweight-n/(prevweight+1));
    }
        // cout<<n<<"end"<<endl;
    return insert(n,tally);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    dp1[1]=1;
    cin>>big;
    cout<<recurse(big)<<endl;
}