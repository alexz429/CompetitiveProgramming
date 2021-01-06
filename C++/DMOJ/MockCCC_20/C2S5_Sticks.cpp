#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,m;
int vals[100000];
int dp[1000][1000][]
int recurse(int l, int r, int at){
    if(l==0&&r==0)return 0;
    if(at>=m)return 0;
    int maxR = min(r,vals[at]/b);
    int best = 0;
    for(;maxR>=0;maxR--){
        int minL = min(l,(vals[at]-maxR*b)/a);
        best = max(best, maxR+minL+recurse(l-minL, r-maxR, at+1));
        // cout<<at<<" "<<best<<endl;
    }
    return best;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int A,B;
    cin>>a>>A>>b>>B;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>vals[i];
    }
    cout<<recurse(A,B,0)<<endl;
}