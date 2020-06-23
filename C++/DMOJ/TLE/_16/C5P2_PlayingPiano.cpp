#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 12;

int MADD(int a, int b){
    return (a+b)%mod;
}
bool check(int b, int a){
    return !(a==b||MADD(a, 4)==b||MADD(a, 7)==b||MADD(a, 10)==b);
}
int arr[100000];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]%=mod;
    }
    int best = 1;
    for(int i=0;i<12;i++){
        int l=0;int r = 0;
        int diff = check(arr[0], i);
        while(true){
            
        // if(i==1)cout<<l<<" "<<r<<" "<<diff<<endl;
            if(diff<=k){
                best = max(best, r-l+1);
                r++;if(r>=n)break;
                diff+=check(arr[r], i);
                // if(i==1)cout<<arr[r]<<" "<<i<<endl;
            }
            else{
                diff-=check(arr[l], i);
                l++;
            }
        }
    }
    cout<<best<<endl;
}