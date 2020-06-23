#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll seg[2001][8000];
#define MOD 1000000007
void insert(int i, int at, int here, int min, int max, int val){
    if(min>here||max<here)return;
    if(min==max&&min==here){
        // cout<<"added "<<val<<" to "<<i<<" "<<at<<endl;
        seg[i][at] += val;
        seg[i][at]%= MOD;
        return;
    }
    int mid = (min+max)/2;
    insert(i, at*2, here, min, mid, val);
    insert(i, at*2+1, here, mid+1, max, val);
    seg[i][at]= (seg[i][at*2]+seg[i][at*2+1])%MOD;
}
ll query(int i, int at, int l, int r, int min, int max){
    if(min>r||max<l)return 0;
    if(min>=l&&max<=r){
        // cout<<"found at "<<i<<" "<<at<<endl;
        return seg[i][at];
    }
    int mid = (min+max)/2;
    return (query(i, at*2, l,r, min, mid) +
    query(i, at*2+1, l,r, mid+1, max))%MOD;
}
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll sum = 0;
    for(int i=0;i<n;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        if(a==1){
            insert(b+c-2, 1, c,0,2000,d);
        }
        else{
            sum+=query(b+c-2, 1,c, c+d, 0, 2000);
            sum%=MOD;
        }
    }
    cout<<sum<<endl;
}