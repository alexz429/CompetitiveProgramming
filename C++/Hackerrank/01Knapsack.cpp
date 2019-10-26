#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[2][2001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int cases;
    cin>> cases;
    for(int count=0;count<cases;count++){
        int max, num;
        cin>>max>>num;
        int vals[2][num+1];
        for(int i=1;i<=num;i++){
            cin>>vals[0][i]>>vals[1][i];
            // printf("%d %d\n", vals[0][i], vals[1][i]);
        }
        int flip = 0;
        for(int i=1;i<=num;i++, flip^=1){
            for(int j=1;j<=max;j++){
                if(j<vals[0][i]){
                    dp[flip][j] = dp[flip^1][j];
                }
                else{
                    dp[flip][j] = std::max(dp[flip^1][j], dp[flip^1][j-vals[0][i]]+vals[1][i]);
                }
                cout<<dp[flip][j]<<" ";
            }
            cout<<endl;
        }
        cout<<dp[flip^1][max]<<endl;
    }
}