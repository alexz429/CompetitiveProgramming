#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    int vals[n];
    for(int i=0;i<n;i++){
        cin>>vals[i];
    }
    for(int i=0;i<q;i++){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            sort(&vals[l-1], &vals[r]);
        }
        else{
            sort(&vals[l-1], &vals[r], greater<int>());
        }
    }
    for(int i=0;i<n;i++){
        cout<<vals[i]<<" \n"[i==n-1];
    }

}