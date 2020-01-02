#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int max;
    cin>>max;
    int vals[max];
    vals[0]=0;
    int money = 0;
    int totalCost = 0;
    pair<int,int> cities[max];
    bool first = true;
    for(int i=0;i<max;i++){
        
        if(i!=0){
            vals[i] = std::max(vals[i-1], totalCost-money);
        }
        int cost, rev;
        cin>>cost>>rev;
        cities[i] = pair<int,int>(cost, rev);
        money+=rev;
        totalCost+=cost;
        if(totalCost>money){
            first=false;
        }
    }
    if(first){
        cout<<1<<endl;
        return 0;
    }
    cout<<endl;
    int best = -2;
    int prev = 0;
    int obstacle =0;
    for(int i=max-1;i>0;i--){
        prev+=cities[i].second-cities[i].first;
        obstacle = min(0, obstacle + cities[i].second-cities[i].first);
        
        if(prev>=vals[i]&&obstacle==0){
            best = i;
        }
        
    }
    cout<<(best+1)<<endl;
}