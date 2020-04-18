#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


pair<int,ll> building[40];
ll connects[40];
ll tally = 0;
int n;
ll k;
ll dp_init(int at){
    if(connects[at]!=-1){
        return connects[at];
    }
    connects[at] = 1;
    for(int i=at+1;i<n;i++){
        if(building[at].first<=building[i].first){
            connects[at]+=dp_init(i);
        }
    }
    return connects[at];
}
void recurse(int at, ll score){
    score+=building[at].second;
    if(score>=k){
        tally+=connects[at];
        // cout<<"add "<<connects[at]<<" at "<<at<<endl;
        return;
    }
    for(int j=at+1;j<n;j++){
        if(building[at].first<=building[j].first){
            recurse(j,score);
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        ll b;
        cin>>a>>b;
        building[i] = {a,b};
    }
    fill(&connects[0], &connects[n], -1);
    for(int i=0;i<n;i++){
        dp_init(i);
        // cout<<connects[i]<<" ";
    }
    // cout<<endl;
    for(int i=0;i<n;i++){
        recurse(i,0);
    }
    cout<<tally<<"\n";
}