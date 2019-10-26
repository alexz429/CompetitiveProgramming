#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define N 1000000
#define M 2000000
queue<int> pq;
vector<vector<int>> graph;
int DONT[N];
int main(){
    cout<<setprecision(9);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int inDeg[n];
    int outDeg[n];
    double out[n];
    fill(&inDeg[0], &inDeg[n], 0);
    fill(&out[0], &out[n], 0);
    fill(&outDeg[0], &outDeg[n], 0);
    out[0]=1;
    for(int i=0;i<n;i++){
        graph.push_back(vector<int>());
    }
    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        from--,to--;
        graph[from].push_back(to);
        inDeg[to]++;
        outDeg[from]++;
        DONT[from] = true;
    }
    for(int i=0;i<n;i++){
        if(inDeg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int next = pq.front();
        pq.pop();
        for(int nextNode:graph[next]){
            if(--inDeg[nextNode]==0){
                pq.push(nextNode);
            }
            out[nextNode] += out[next]/outDeg[next];
        }
    }
    for(int i=0;i<n;i++){
        if(!DONT[i]){
            cout<<out[i]<<endl;
        }
    }

}
