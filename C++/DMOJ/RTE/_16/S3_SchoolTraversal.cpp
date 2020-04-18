#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bin[15][6000];
vector<vector<pair<int, ll>>> graph;
ll psa[6000];
ll dep[6000];
bool visit[6000];
void recurse(int at){
    visit[at]= true;
    for(pair<int,ll> next:graph[at]){
        if(visit[next.first])continue;
        psa[next.first] = psa[at]+next.second;
        dep[next.first] = dep[at] +1;
        bin[0][next.first] = at;
        recurse(next.first);
    }
}

int lca(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=14;i>=0;i--){
        if(bin[i][a] != -1 && dep[bin[i][a]] >= dep[b]) a = bin[i][a];
    }
    if(a==b)return a;
    for(int i=14;i>=0;i--){
        if(bin[i][a] != -1&& bin[i][b] != -1&& bin[i][a] != bin[i][b]){
            a = bin[i][a], b=bin[i][b];
        }
    }
    return bin[0][a];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        graph.push_back(vector<pair<int,ll>>());
    }
    for(int i=0;i<n-1;i++){
        int from, to;ll weight;
        cin>>from>>to>>weight;
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }
    bin[0][0] = -1;
    recurse(0);
    // for(int i=0;i<n;i++){
    //     cout<<bin[0][i]<<" ";
    // }
    // cout<<"\n";
    for(int i=1;i<15;i++){
        for(int j=0;j<n;j++){
            if(bin[i-1][j]==-1){
                bin[i][j]=-1;
            }
            else{
            bin[i][j] = bin[i-1][bin[i-1][j]];
            }
            // cout<<bin[i][j]<<" ";
        }
        // cout<<"\n";
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int from, to;
        cin>>from>>to;
        cout<<psa[from]+psa[to]-psa[lca(from,to)]*2<<"\n";
    }
}