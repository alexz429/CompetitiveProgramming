#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,p;
        cin>>n>>p;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(&arr[0], &arr[n]);
        int best = 0;
        int sum = 0;
        for(int i=0;i<p-1;i++){
            sum += (arr[p-1]-arr[i]);
        }
        best = sum;
        for(int i=0;i<n-p;i++){
            // cout<<best<<endl;
            sum-= (arr[i+p-1]-arr[i]);
            sum += (arr[i+p]-arr[i+p-1])*(p-1);
            best = min(best, sum);
        }
        cout<<"Case #"<<i+1<<": "<<best<<"\n";
    }
}