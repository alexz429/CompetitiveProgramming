#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int val[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    sort(&val[0], &val[n]);
    for(int i=0;i<n;i++){
        cout<<val[i];
        if(i<n-1){
            cout<<" ";
        }
    }
    cout<<"\n";
}