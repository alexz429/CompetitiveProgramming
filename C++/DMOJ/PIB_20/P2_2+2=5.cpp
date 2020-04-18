#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll batch = n/2.5;
    double rem = n-batch*2.5;
    // cout<<batch<<"\n";
    // cout<<rem<<"\n";
    ll out = batch*7+rem/0.5+(rem==2?3:1);
    cout<<out<<"\n";
}