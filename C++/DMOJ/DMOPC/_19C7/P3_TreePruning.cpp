#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[1000000];
ll sizes[1000000];
int parent[1000000];
int findParent(int a){
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

bool isConnected(int a, int b){
    return findParent(a) == findParent(b);
}
void connect(int a, int b){
    if(isConnected(a,b))return;
    sizes[findParent(b)] += sizes[findParent(a)];
    parent[findParent(a)] = findParent(b);
    
}

set<int> visit;
vector<vector<int>> graph;
int n; ll k;
ll tally = 0;
void recurse(int at){
    if(tally>=k)return;
    if(visit.find(at)!=visit.end())return;
    tally+=arr[at];
    visit.insert(at);
    
    // cout<<at<<" "<<tally<<" "<<arr[at]<<endl;
    for(int next: graph[at]){
        recurse(next);
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        graph.push_back(vector<int>());
        parent[i] = i;
        cin>>arr[i];
        sizes[i] = arr[i];
        if(arr[i]>k*2){
            sizes[i] = -1;
        }
        if(arr[i]>=k&&arr[i]<=k*2){
            cout<<1<<"\n";
            cout<<i+1<<"\n";
            return 0;
        }
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(arr[a]>k*2||arr[b]>k*2)continue;
        connect(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(sizes[findParent(i)]==-1||sizes[findParent(i)]<k)continue;
        recurse(i);
        cout<<visit.size();
        bool end = true;
        for(int next: visit){
            if(end){
                cout<<"\n";
                end = false;
            }
            else{
                cout<<" ";
            }
            cout<<next+1;
        }
        cout<<"\n";
        return 0;
    }
    cout<<-1<<"\n";


}