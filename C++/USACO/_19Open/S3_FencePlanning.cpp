#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> cows[100004];
int parent[100004];
int findParent(int at){
    if(parent[at]==at){
        return at;
    }
    return parent[at] = findParent(parent[at]);
}

bool isConnected(int a, int b){
    return findParent(a) == findParent(b);
}

void merge(int a, int b){
    parent[findParent(a)] = findParent(b);
}

map<int, pair<pair<int,int>, pair<int,int>>> things;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        parent[i] = i;
        int x,y;
        cin>>x>>y;
        cows[i] = {x,y};
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        merge(a-1,b-1);
    }
    for(int i=0;i<n;i++){
        int next = findParent(i);
        if(things.find(next)==things.end()){
            things[next] = {{cows[i].first,cows[i].second},{cows[i].first, cows[i].second}};   
        }
        else{
            pair<pair<int,int>, pair<int,int>> lol = things[next];
            things[next] = {{min(cows[i].first, lol.first.first), min(cows[i].second, lol.first.second)}, {max(cows[i].first, lol.second.first), max(cows[i].second, lol.second.second)}};
        }
    }
    int best = -1;
    for(pair<int,pair<pair<int,int>,pair<int,int>>> next: things){
        int comp = (next.second.second.first-next.second.first.first+next.second.second.second-next.second.first.second)*2;
        if(best==-1){
            best = comp;
        }
        else{
            best = min(best,comp);
        }
    }
    cout<<best<<"\n";
}