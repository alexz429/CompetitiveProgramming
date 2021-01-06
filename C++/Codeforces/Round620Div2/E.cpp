#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
int dep[100004];
int lca[18][100004];

vector<vector<int>> graph;
int n;
void recurse(int at, int from, int deep){
    dep[at]=deep;
    lca[0][at] = from;
    for(int next: graph[at]){
        if(next==from)continue;
        recurse(next, at, deep+1);
    }
}
void lca_set(){
    for(int i=1;i<18;i++){
        for(int j=0;j<n;j++){
        if(lca[i-1][j]!=-1){
            lca[i][j] = lca[i-1][lca[i-1][j]];
        }
        else lca[i][j]=-1;
        }
    }
}
int lca_q(int a, int b){
    // cout<<"START"<<a<<" "<<b;
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=17;i>=0;i--){
        if(lca[i][a]!=-1&&dep[lca[i][a]]>= dep[b]) a= lca[i][a];
    }
    // cout<<"END"<<a<<" "<<b;
    if(a==b) return a;
    for(int i=17;i>=0;i--){
        if(lca[i][a]!=-1&&lca[i][b]!=-1&&lca[i][a]!=lca[i][b]){
            a=lca[i][a]; b=lca[i][b];
        }
    }
    return lca[0][a];
}
int dis(int a, int b){
    return dep[a]+dep[b]-2*dep[lca_q(a,b)];
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        graph.push_back(vector<int>());
    }
    for(int i=0;i<n-1;i++){
        int from,to;
        cin>>from>>to;
        from--,to--;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    fill(&lca[0][0], &lca[1][0], -1);

    // cout<<"start recurse"<<endl;
    recurse(0, -1, 0);
    // cout<<"start lca"<<endl;
    lca_set();
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<6;j++){
    //         cout<<lca[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b,x,y,c;
        cin>>a>>b>>x>>y>>c;
        a--;b--;x--;y--;
        int mid = lca_q(x,y);
        ll normDis = dis(x,y);
        ll altDis = min(dis(x,a)+1+dis(y,b), dis(x,b)+1+dis(y,a));
        // cout<<dis(x,a)<<" "<<dis(y,b)<<" "<<dis(y,a)<<" "<<dis(x,b)<<endl;
        ll altDis2= min(dis(x,a)+dis(y,a), dis(x,b)+dis(y,b));
        // cout<<y<<" "<<b<<" "<<lca_q(y,b)<<endl;
        // cout<<normDis<<" "<<altDis<<" "<<altDis2<<endl;
        ll cycle = dis(a,b)+1;
        if(normDis<=c){
            int diff = c-normDis;
            if(diff%2==0){
                cout<<"YES"<<endl;
                continue;
            }
        }
        if(altDis<=c){
            int diff = c-altDis;
            if(diff%2==0||diff%cycle==0){
                cout<<"YES"<<endl;
                continue;
            }
        }
        if(altDis2<=c){
            int diff = c-altDis2;
            if(diff%2==0||diff%cycle==0){
                cout<<"YES"<<endl;
                continue;
            }
        }
        cout<<"NO"<<endl;
    }
}