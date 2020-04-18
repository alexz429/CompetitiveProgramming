#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m,n;
        cin>>m>>n;
        int high = n;
        int low = n;
        pair<int,pair<int,int>> vals[m];
        for(int j=0;j<m;j++){
            int t,l,r;
            cin>>t>>l>>r;
            vals[j] = {t,{l,r}};
        }
        sort(&vals[0], &vals[m]);
        int prevTime=0;
        bool passed = true;
        for(int j=0;j<m;j++){
            int t,l,r;
            t = vals[j].first-prevTime;l=vals[j].second.first;r=vals[j].second.second;
            prevTime = vals[j].first;
            // cout<<t<<" "<<l<<" "<<r<<endl;
            high += t;
            low-=t;
            // cout<<high<<" "<<low<<endl;
            if(high<l||low>r){
                cout<<"NO"<<"\n";
                passed = false;
                break;
            }
            high=min(high, r);
            low = max(low, l);
            // cout<<high<<low<<endl;
        }
        if(passed){
            cout<<"YES"<<"\n";
        }
    }
}