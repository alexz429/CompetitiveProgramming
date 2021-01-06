#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// this version uses LCA + PSA for the solution

int bin[20][100000];
bool cow[100000];
vector<vector<int>> graph;
bool visit[100000];
void setup(int at){
    visit[at] = true;
    for(int next: graph[at]){
        
    }
}

int main(){
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(0);
     int n,m;
    cin>>n>>m;
    string in;
    cin>>in;
    for(int i=0;i<n;i++){
        cow[i] = in[i] == 'H';
        graph.push_back(vector<int>());
    }
    for(int i=0;i<=n-1;i++){
        int from, to;
        cin>>from>>to;
        from--;to--;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}