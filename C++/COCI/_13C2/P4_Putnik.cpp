#include <bits/stdc++.h>
using namespace std;
int dis[1500][1500];
int dp[1500][1500];

    int lim;
int recurse(int l, int r){
    if(dp[l][r]!=0)return dp[l][r];
    int next=max(l,r)+1;
    if(next==lim) return 0;
    dp[l][r]=min(dis[next][l]+recurse(next,r),dis[next][r]+recurse(l,next));
    return dp[l][r];
}

int main(){
    scanf("%d", &lim);
    for(int count=0;count<lim;count++){
        for(int count2=0;count2<lim;count2++){
            scanf("%d",&dis[count][count2]);
        }
    }
    printf("%d\n", recurse(0,0));
    
}