#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    ll val[n];
    ll best = -1;
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<n/2+1;i++){
        // cout<<i<<endl;
        if(n%i==0){
            ll sums[i];
            int phases = n/i;
            for(int j=0;j<i;j++){
                int lmao[phases];
                for(int k=0;k<phases;k++){
                    lmao[k]=val[j+i*k];
                }
                // cout<<endl;
                sort(&lmao[0], &lmao[phases]);
                sums[j] =lmao[phases/2];
            }
            // for(int j=0;j<i;j++){
            //     cout<<sums[j]<<" ";
            // }
            // cout<<endl;
            ll tally = 0;
            for(int j=0;j<n;j++){
                tally += abs(sums[j%i]-val[j]);
                if(best!=-1&&tally>best){
                    tally = -1;
                    break;
                }
            }
            if(tally==-1)continue;
                
            if(best==-1){
                best = tally;
            }
            else{
                best = min(tally, best);
            }
            // cout<<best<<" "<<i<<endl;
        }
    }
    cout<<best<<endl;
}