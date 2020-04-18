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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll su = c+d;
        ll diff = b-a;
        ll ans = diff/su;
        if(ans*su!=diff){
            cout<<-1<<"\n";
        }
        else{
            cout<<ans<<"\n";
        }
    }
}