#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n,m,q;
    cin>>n>>m>>q;
    set<pair<ll, ll>> huh;
    vector<ll> things;
    ll prev = n;
    ll index=0;
    ll offset=0;
    ll low = 1000000;
    ll prevVal=1000000;
    ll prevLow=1000000;
    for(ll i=0;i<q;i++){
        ll d;
        ll p;
        cin>>d>>p;
        if(d!=prev){
            things.push_back(1-offset);
            
            // cout<<low<<" "<<index<<" "<<things[index]<<endl;
            huh.insert(make_pair(low, index++));
               things.push_back(prev-d);
                prevLow = prevVal;
               offset=1; 
            

            // cout<<prevVal<<" "<<index<<" "<<things[index]<<endl;
            huh.insert(make_pair(prevVal, index++));
            low = 1000000;
            prev = d;
        }
        prevVal=p;
        low = min(low, p);
        if (offset==1&&prevLow>low){
            // cout<<"oop"<<endl;
            things[index-1]--;
            offset=0;
        }
        low = min(low, p);
    }
    things.push_back(1-offset);
    // cout<<low<<" "<<index<<" "<<things[index]<<endl;
    huh.insert(make_pair(low, index++));
    
    things.push_back(prev-1);
    huh.insert(make_pair(prevVal, index++));
    
    ll cost = 0;
    ll out = 0;
    while(m>0){
        pair<ll, ll> next = *huh.begin();
        huh.erase(huh.begin());
        out+=next.first*things[next.second];
        m -= things[next.second];
        cost = next.first;
    }
    out += m*cost;
    cout<<out<<endl;
}