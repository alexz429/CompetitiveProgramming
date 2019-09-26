#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int> stuff;
int C,D,K,coins[101];
pair<int,double> types[100], sorted[100];
int cur=1,pre=0, biggest=0;
double dp[2][200001], best=0, total=0;
int lim=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>C>>D>>K;
    
    fill(&dp[0][0], &dp[1][200001], -1);

    for(int count=0;count<D;count++){
        int val;
        float weight;
        cin>>val>>weight;
        types[count]= pair<int,double>(val,weight);
sorted[count]= pair<int,double>(val,weight);
    }
    sort(&sorted[0], &sorted[D]);
    for(int count=1;count<=K;count++){
        cin>>coins[count];
        coins[count]--;
        if(count==1){
            
        dp[0][types[coins[count]].first]=types[coins[count]].second;
        }
        biggest=max(biggest,types[coins[count]].first);
        total+=types[coins[count]].second;
        lim+=types[coins[count]].first;
    }
    if(lim<C){
        cout<<"too poor"<<endl;
        return 0;
    }
    best=1e9;
    // cout<<"____________-"<<endl;
    for(int count=2;count<=K;count++){
        dp[cur][0]=0;
        for(int i=1;i<=lim;i++){
            double give=dp[pre][i];
            double take=-1;
            if(i-types[coins[count]].first>=0&&dp[pre][i-types[coins[count]].first]!=-1){
                take=dp[pre][i-types[coins[count]].first]+types[coins[count]].second;
            }
            // if(i==10){
            //     cout<<take<<" "<<give<<endl;
            // }
            dp[cur][i]=max(give,take);
            // if(i==1){
            //     cout<<give<<" "<<take;
            // }
            // cout<<dp[cur][i]<<" ";
        }
        // cout<<endl;
        pre^=1;
        cur^=1;
    }
    for(int i=C;i<=lim;i++){
        
        if(dp[pre][i]==-1)continue;
        double back=0;
        int rem=i-C;
        for(int j=D-1;j>-1;j--){
            back+=sorted[j].second*(rem/sorted[j].first);
            rem%=sorted[j].first;
        }
        
        best=min(best, total-dp[pre][i]+back);
        // cout<<i<<" "<<total-dp[pre][i]+back<<" "<<back<<" "<<total<<endl;
    }
    cout<<fixed<<setprecision(2)<<best<<endl;
}
