#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int arr[3];
    cin>>arr[0];
    cin>>arr[1];
    cin>>arr[2];
    sort(&arr[0], &arr[3]);
    cout<<(arr[0]+arr[1]>arr[2]?"yes":"no")<<"\n";
}