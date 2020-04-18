#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M; string s[50]; vector<pair<int, pair<int,int>>> graph[51][51]; int visited[51][51];
int ans = -1;
// let node[x][i] be the representation of segment i of code x
// x[i] -> y[j] implies a word can fit to bring the current position to y[j]
// then djikstra or something I guess
// since x,i<=50, combine node[x][i] into node[x*50+i] for easier stuff
int main(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            visited[i][j] = 0x3f3f3f3f;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>s[i];
    }
    for(int i=0;i<N;i++){ 
        for(int j=0;j<s[i].size();j++){
            for(int k=0;k<N;k++){
                if(i==k&&j==0)continue;
                bool lim = true;
                int limit = min(s[i].size()-j,s[k].size());
                for(int l=0;l<limit;l++){
                    if(s[i][l+j]!=s[k][l]){
                        lim = false;
                        break;
                    }
                }
                if(lim){
                    // cout<<i<<" "<<j<<" "<<k<<" "<<limit<<endl;
                    if(limit + j == s[i].size()){
                        graph[i][j].push_back({limit,{k,limit}});
                    }
                    else{
                        graph[i][j].push_back({limit,{i,limit+j}});
                    }
                }
            }
        }
    }
    set<pair<int,pair<int,int>>> pqueue;
    for(int i=0;i<N;i++){
        pqueue.insert({0,{i,0}});
    }
    while(!pqueue.empty()){
        pair<int,pair<int,int>> next = *pqueue.begin();
        pqueue.erase(pqueue.begin());
        // cout<<next.second.first<<" "<<next.second.second<<" "<<next.first<<" "<<pqueue.size()<<endl;
        if(visited[next.second.first][next.second.second]<=next.first)continue;
        visited[next.second.first][next.second.second] = next.first;
        if(s[next.second.first].size()==next.second.second){
            cout<<next.first<<endl;
            return 0;
        }
        for(pair<int,pair<int,int>> connect:graph[next.second.first][next.second.second]){
            if(visited[connect.second.first][connect.second.second]>visited[next.second.first][next.second.second]+connect.first){
            // cout<<"link"<<connect.first<<" "<<connect.second.first<<" "<<connect.second.second<<endl;
                pqueue.insert({visited[next.second.first][next.second.second]+connect.first,{connect.second.first,connect.second.second}}); 
            }
        }
    }
    cout<<-1<<"\n";
}