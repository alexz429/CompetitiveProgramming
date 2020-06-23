#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[10000];
int w[10000];
vector<vector<pair<int, int>>> graph;
int c, k, tally;
void recurse(int at, int add, int from){
    w[at] = add;
    for(pair<int,int> next: graph[at]){
        if(next.first==from)continue;
        recurse(next.first, next.second, at);
        arr[at] += arr[next.first];
        w[at]+=w[next.first];
    }
    if(at==0)return;
    if(arr[at]>=c&&w[at]<=k){
        tally++;
    }
}
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int n; cin>>n>>c>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        graph.push_back(vector<pair<int,int>>());
    }
    for(int i=0;i<n-1;i++){
        int from, to, w;cin>>from>>to>>w;
        graph[from-1].push_back({to-1,w});
        graph[to-1].push_back({from-1,w});
    }
    recurse(0,0,-1);
    cout<<tally<<endl;

}