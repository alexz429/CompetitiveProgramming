#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int lca[18][100004];
ll dep[100004];
vector<vector<pair<int,ll>>> graph;
int n,d;
void dfs(int at, int from, ll length){
    lca[0][at] = from;
    dep[at] = length;
    for(pair<int,int> next: graph[at]){
        if(next.first==from)continue;
        dfs(next.first, at, length+next.second);
    }
}
void lca_set(){
    for(int i=1;i<18;i++){
        for(int j=0;j<n;j++){
            if(lca[i-1][j]==-1){
                lca[i][j] = -1;
            }
            else{
                lca[i][j] = lca[i-1][lca[i-1][j]];
            }
        }
    }
}
int lca_q(int a, int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=17;i>=0;i--){
        if(lca[i][a]!=-1&&dep[lca[i][a]]>=dep[b]){
            a= lca[i][a];
        }
    }
    if(a==b)return a;
    for(int i=17;i>=0;i--){
        if(lca[i][a]!=-1&&lca[i][b]!=-1&&lca[i][a]!=lca[i][b]){
            a= lca[i][a];
            b=lca[i][b];
        }
    }
    return lca[0][a];
}
ll dis(int a, int b){
    return dep[a]+dep[b]-2*dep[lca_q(a,b)];
}
int main(){
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    for(int i=0;i<n;i++){
        graph.push_back(vector<pair<int,ll>>());
    }
    for(int i=0;i<n-1;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        from--;to--;
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }
    dfs(0,-1,0);
    // for(int i=0;i<n;i++){
    //     cout<<dep[i]<<" ";
    // }
    // cout<<endl;
    int test[4] = {1};
    lca_set();
    int pl=0;
    int pr= 0;
    ll l = 0;
    ll r = 0;
    for(int i=0;i<d;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        // cout<<dis(a,b)<<endl;
        l += dis(pl, b)+dis(b,a);
        r += dis(pr, a)+dis(a,b);
        pl = a;
        pr = b;
        // cout<<l<<" "<<r<<endl;
    }
    cout<<min(l,r)<<endl;
}