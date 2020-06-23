#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<pair<int,int>> pqueue;

vector<vector<pair<int,int>>> graph;

int shortest[2][5000];

void djikstra(int at, int target, int arr){
    pqueue.clear();
    fill(&shortest[arr][0], &shortest[arr][5000], (int)1e9);
    shortest[arr][at] = 0;
    pqueue.insert({0, at});
    while(!pqueue.empty()){
        
        int next = pqueue.begin()->second;
        pqueue.erase(pqueue.begin());
        for(pair<int,int> nextEdge: graph[next]){
            int comp = shortest[arr][next] + nextEdge.second;
            if(comp<shortest[arr][nextEdge.first]){
                shortest[arr][nextEdge.first] = comp;
                pqueue.insert({comp, nextEdge.first});
            }
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        graph.push_back(vector<pair<int,int>>());
    }
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[--a].push_back({--b, c});
        graph[b].push_back({a,c});
    }
    djikstra(0,n-1, 0);
    djikstra(n-1,0,1);
    // for(int i=0;i<n;i++){
    //     cout<<shortest[0][i]<<" "<<shortest[1][i]<<endl;
    // }
    int best = (int)1e9;
    for(int i=0;i<n;i++){
        for(auto nextEdge: graph[i]){
            int calc = nextEdge.second+shortest[0][i] + shortest[1][nextEdge.first];
            if(calc==shortest[0][n-1])continue;
            best = min(calc, best);
        }
    }
    cout<<best<<endl;
}