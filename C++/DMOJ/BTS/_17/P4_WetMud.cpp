#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> drying;
set<int> available;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,j;
    cin>>n>>m>>j;
    int at = 0;
    int maxTime = 0;
    for(int i=0;i<m;i++){
        int at, time;
        cin>>at>>time;
        maxTime = max(maxTime, time);
        drying.insert({time, at});
    }
    available.insert(n+1);
    for(int i=0;i<=maxTime;i++){
        // cout<<i<<endl;
        while(!drying.empty()&&(*drying.begin()).first<=i){
            available.insert((*drying.begin()).second);
            drying.erase(drying.begin());
        }
        while(!available.empty()&&*available.begin()-at<=j){
            at=max(at, *available.begin());
            available.erase(available.begin());
        }
        if(at==n+1){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

}