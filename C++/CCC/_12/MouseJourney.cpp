#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[25][25];
int width, height;
int rec(int x, int y){
    // cout<<x<<" "<<y<<endl;
    if(x<0||x>=width||y<0||y>=height)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    return dp[x][y] = rec(x-1,y)+rec(x,y-1);
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>width>>height;
    int cats;
    cin>>cats;
    int j = 0;
    for(int i=0;i<width;i++){
        j = 0;
        for(;j<height;j++){
            dp[i][j] = -1;
        }
    }
    dp[0][0]=1;
    int x,y;
    for(;cats > 0;cats--){

        cin>>x>>y;
        x--;y--;
        dp[x][y] = 0;
    }
    cout<<rec(width-1,height-1)<<"\n";
}