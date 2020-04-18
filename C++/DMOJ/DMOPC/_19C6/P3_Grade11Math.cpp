#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (ll)(1e9+7)
#define S 500000
ll dp[S+4];

int n, m;
void init(){
    ll temp = 1;
    dp[0] = 1;
    for(int i=1;i<=S+1;i++){
        temp=(temp*2)%MOD;
        dp[i] = temp;
    }
}

ll out = 0;
bool seg[4*S];
void add(int at, int l, int r, int min, int max){
    if(r<min||l>max||seg[at])return;
    if(l==r){
        seg[at] = true;
        out = (out+dp[n-l-1])%MOD;
        return;
    }
    int mid = (l+r)/2;
    add(at*2, l, mid, min, max);
    add(at*2+1, mid+1, r, min, max);
    seg[at]=seg[at*2]&seg[at*2+1];
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    init();
    
    // for(int i=0;i<40;i++){
    //     cout<<dp[i]<<endl;
    // }
    cin>>n>>m;
    string next;
    cin>>next;
    bool going = false;
    int l = 0;
    int r = 0;
    for(int i=0;i<next.length();i++){
        if(next[i]=='1'){
            add(1, 0,n,i,i);
        }
    }
    // cout<<out<<endl;
    // cout<<"done"<<out<<endl;
    // for(int i=0;i<segments.size();i++){
    //     cout<<segments.front().first<<" "<<segments.front().second<<endl;
    //     segments.push_back(segments.front());
    //     segments.pop_front();
    // }
    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        from--;to--;
        add(1,0,n,from,to);
        cout<<out<<endl;
    }
}