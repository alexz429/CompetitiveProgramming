#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double dp[1000004];
int burg[1000004];
map<int, int> visit;
int n;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>burg[i];
    }
    dp[n-1] = burg[0]==burg[n-1]?1:0;
    visit[burg[n-1]] = n-1;
    double sum=dp[n-1];
    for(int i=n-2;i>=0;i--){
        if(visit.find(burg[i])==visit.end()){
            visit[burg[i]] = i;
            if(burg[i] == burg[0]){
                dp[i] = 1;
            }
            else{
                // cout<<"hit at "<<i<<" "<<psa[i+1]<<endl;
                dp[i] = (sum+1)/(n-i);
            }
        }
        else{
            dp[i] = dp[visit[burg[i]]];
        }
        sum += dp[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout<<setprecision(9)<<sum/n<<endl;

}