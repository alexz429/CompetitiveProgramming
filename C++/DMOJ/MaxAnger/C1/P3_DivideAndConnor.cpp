#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[2000000];
bool first = true;

void recurse(int l, int r){
    // cout << l << " " << r<<endl;
    if(l==r){
        if(!first)cout << " ";
        first = false;
        cout<<arr[l];
        return;
    }
    recurse(l + (r - l + 1)/3*2, r);
    recurse(l, l + (r - l + 1)/3-1);
    recurse(l + (r - l + 1)/3, l + (r - l + 1)/3*2-1);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    recurse(0, n-1);
}