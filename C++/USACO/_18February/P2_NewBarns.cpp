#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
typedef long long ll;

int lca[20][100004];
int dep[100004];
int parent[100004];
vector<pair<int,pair<int,int>>> groups;
int tally=1;
int group = 0;
int lcaSearch(int a, int b){
    
    // cout<<"pair"<<a<<" "<<b<<endl;
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=19;i>=0;i--){
        if(lca[i][a]!=-1&&dep[lca[i][a]]>=dep[b]){
            a = lca[i][a];
        }
    }
    // cout<<"pair"<<a<<" "<<b<<endl;
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(lca[i][a] != -1 && lca[i][a] != -1 &&lca[i][a] != lca[i][b]){
            a= lca[i][a], b=lca[i][b];
        }
    }
    return lca[0][a];
}
int dis(int a, int b){
    int parent = lcaSearch(a,b);
    // cout<<"parent"<<parent<<endl;
    return dep[a]+dep[b]-2*dep[parent];
}
int query(int n){
    // cout<<parent[n]<<endl;
    // cout<<dis(n, groups[parent[n]].second.first)<<endl;
    // cout<<dis(n,groups[parent[n]].second.second)<<endl;
    return max(dis(n, groups[parent[n]].second.first), dis(n,groups[parent[n]].second.second));
}
void add(int n){
    dep[tally] = (n==-1)?1:dep[n]+1;
    lca[0][tally] = n;
    for(int i=1;i<20;i++){
        if(lca[i-1][tally] == -1){
            lca[i][tally]=-1;
        }
        else{
            lca[i][tally] = lca[i-1][lca[i-1][tally]];
        }
    }
    if(n==-1){
        groups.push_back({0,{tally,tally}});
        parent[tally] = group;
        group++;
    }
    else{
        parent[tally] = parent[n];
        int test = dis(tally,groups[parent[tally]].second.first);
        // cout<<test<<endl;
        if(test>groups[parent[tally]].first){
            groups[parent[tally]].first=test;
            groups[parent[tally]].second.second=tally;
        }
        else{
            test = dis(tally,groups[parent[tally]].second.second);
            // cout<<test<<endl;
            if(test>groups[parent[tally]].first){
                groups[parent[tally]].first=test;
                groups[parent[tally]].second.first=tally;
            }
        }
    }
    tally++;
    // for(pair<int,pair<int,int>> next: groups){
    //     cout<<next.first<<" "<<next.second.first<<" "<<next.second.second<<endl;
    // }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string next; int com;
        
        cin>>next>>com;
        // cout<<next<<" "<<com<<endl;
        if(next[0] =='Q'){
            cout<<query(com)<<endl;
        }
        else{  
            add(com);
        }
        // cout<<"done"<<endl;
    }
}