#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[200000];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(&arr[0], &arr[n]);
    int l=0;
    int r = 0;
    int diff = 0;
    int best = 1;
    while(true){
        // cout<<diff<<" "<<l<<" "<<r<<endl;
        if(diff<=k){
            best = max(best, r-l+1);
            r++;
            if(r>=n)break;
        }
        else{
            l++;
        }
        diff = arr[r]-arr[l];
    }
    cout<<best<<endl;

}