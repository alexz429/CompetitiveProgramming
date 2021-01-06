#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[1000];
vector<vector<int>> graph;
int main(){
    int node,start,end,edges;
    cin>>node>>start>>end>>edges;
    start--;
    end--;
    for(int i=0;i<node;i++){
        graph.push_back(vector<int>());
    }
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
    }
    int steps = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int next = q.front();
            q.pop();
            if(next == end){
                cout<<steps<<endl;
                return 0;
            }
            if(visited[next])continue;
            visited[next] = true;   
            for(int adj:graph[next]){
                q.push(adj);
            }
        }
        steps++;
    }
}