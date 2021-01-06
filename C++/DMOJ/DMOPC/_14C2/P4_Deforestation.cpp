#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[1000001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    int m;
    cin>>m;
    while(m--){
        int a,b;cin>>a>>b;
        cout<<arr[b+1]-arr[a]<<"\n";
    }
}