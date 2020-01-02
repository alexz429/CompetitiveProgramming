#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool given[200001];
bool taken[200001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int num;
    cin>>num;
    vector<int> log;
    for(int i=0;i<num;i++){
        int next;
        cin>>next;
        log.push_back(next);
        if(next!=0){
            given[i] = true;
            taken[next-1] = true;
        }
    }
    map<int,int> wild;
    int point = 0;
    for(int i=0;i<num;i++){
        if(!given[i]){
            while(taken[point]){
                point++;
            }
            wild[i] = point;
            taken[point] = true;
        }
    }
    vector<int> oops;
    for(pair<int,int> next: wild){
        // cout<<next.first<<" "<<next.second<<endl;
        if(next.first==next.second){
            oops.push_back(next.first);
        }
    }
    if(oops.size()>1){
        int prev = -1;
        int first= -1;
        for(int next:oops){
            if(prev==-1){
                first = next;
            }
            else{
                wild[prev] = next; 
            }
            prev= next;
        }
        wild[prev] = first;
    }
    else if (oops.size()==1){
        for(pair<int,int> next: wild){
            if(next.first!=oops[0]){
                wild[oops[0]] = next.second;
                wild[next.first] = oops[0];
                break;
            }
        }
    }
    for(int i=0;i<num;i++){
        if(log[i]==0){
            cout<<(wild[i]+1)<<" ";
        }
        else{
            cout<<log[i]<<" ";
        }
    }

}