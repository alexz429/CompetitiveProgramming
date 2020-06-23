#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[1000001];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int next; cin>>next;
        arr[next]=1;
    }
    for(int i=1;i<=1000000;i++){
        if(arr[i]){
            arr[i] = arr[i-1]+1;
        }
        else{
            arr[i] = arr[i-1];
        }
    }
    cin>>n;
    while(n--){
        int next;cin>>next;
        cout<<next-arr[next]<<endl;
    }
}