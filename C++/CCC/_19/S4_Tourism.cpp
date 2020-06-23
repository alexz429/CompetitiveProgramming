#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll *vals;
ll *seg;
int n,k;
void init_seg(int at, int left, int right){
    if(left==right){
        seg[at] = vals[left];
        return;
    }
    int mid = (left+right)/2;
    init_seg(at*2, left, mid);
    init_seg(at*2+1, mid+1, right);
    seg[at] = max(seg[at*2],seg[at*2+1]);
}
ll query(int at, int left, int right, int l, int r){
    if(right<l||left>r){
        return 0;
    }
    if(left>=l&&right<=r){
        return seg[at];
    }
    int mid = (left+right)/2;
    return max(query(at*2,left, mid, l,r),query(at*2+1, mid+1, right, l,r));
}
ll seg_q(int left, int right){
    return query(1,0,n,left, right);
}
vector<vector<int>> dp;
int day, space;
ll recurse(int d, int s, int cur){
    if(d>=day)return 0;
    if(cur>=n) return 0;
    if(s>k)return 0;
    if(dp[d][s]!=0)return dp[d][s];
    if(s==0){
        return dp[d][s] = seg_q(cur, cur+k-1)+recurse(d+1,0,cur+k);
    }
    if(d==day-1){
        return dp[d][s] = seg_q(cur, cur+s-1);
    }
    ll sum = 0;
    int r = min(n-1, (d+1)*k+space-1);
    ll temp = seg_q(cur+k,r);
    for(int i=k, t=0;i>=s;i--, t++){
        if(cur+i-1>n-1)continue;
        ll temp2 = seg_q(cur, cur+i-1);
        if(temp>=vals[cur+i]&&i<k)continue;
        if(i<k) temp = vals[cur+i];
        sum = max(sum, temp2+recurse(d+1, (s+t)%k,cur+i));
    }
    return dp[d][s] = sum;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    space = n%k;
    day;
    vals = new ll[n];
    seg = new ll[4*n];
    if(n%k==0){   
        day = n/k;
    }
    else{
        day = n/k+1;
    }
    for(int i=0;i<n;i++){
        cin>>vals[i];
    }
    dp = vector<vector<int>>(day+1);
    for(int i=0;i<=day;i++){
        dp[i] = vector<int>(k+1);
    }
    // cout<<day<<" "<<space<<endl;
    cout<<recurse(0,n%k,0)<<endl;

}