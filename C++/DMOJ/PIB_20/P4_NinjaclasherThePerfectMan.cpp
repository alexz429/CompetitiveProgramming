#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 100000007
ll fac[2005];
vector<vector<int>> graph;

bool debug = false;
ll lol(ll a){
    // cout<<a<<" ";
    ll output = 1;
    a%=MOD;
    int b = MOD-2;
    while(b>0){
        if(b%2==1){
            output = (output*a)%MOD;
        }
        b/=2;
        a*=a;
        a%=MOD;
    }
    // if(debug)cout<<output<<"\n";
    return output;
}
ll nCr(ll n, ll r){
    if(n<r)return 0;    
    if(n==r)return 1;
    return (fac[n]*lol(fac[r])%MOD*lol(fac[n-r])%MOD)%MOD; 
}
int query(int at, int children, int depth, int prev){
    if(depth==0)return 1;
    ll ways = 0;
    ll sub = 0;
    for(int next: graph[at]){
        if(next==prev)continue;
        int temp = query(next, children, depth-1, at);
        ways+=temp;
        sub+=nCr(temp, children);
        sub%=MOD;
    }
    ways = nCr(ways, children);
    
    if(debug){
        cout<<at<<" "<<children<<" "<<depth<<" || "<<ways<<" "<<sub<<"\n";
    }
    ways%=MOD;
    ways = (ways+MOD-sub)%MOD;
    return ways;

}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    fac[0] =1;
    for(int i=1;i<2005;i++){
        fac[i] = fac[i-1]*i%MOD;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        graph.push_back(vector<int>());
    }
    for(int i=1;i<n;i++){
        int from,to;
        cin>>from>>to;
        from--;to--;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    ll tally = 0;
    for(int i=0;i<n;i++){
        ll prev = -1;
        for(int j=2;j<2000;j++){
            for(int k=1;prev!=0;k++){
                prev = query(i, j, k, -1);
                debug=false;
                // if(prev!=0){
                    
                // cout<<i<<" "<<j<<" "<<k<<" "<<prev<<"\n";
                // }
                tally += prev;
                tally%=MOD;
            }
            prev=-1;
        }
    }
    tally+=n;
    tally%=MOD;
    cout<<tally<<"\n";
}