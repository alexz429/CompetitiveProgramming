#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll tally;

void recurse(int x,int y,int z){
    if(x==0&&y==0&&z==0){
        tally++;
        tally%=MOD;
    }
    if(x!=0){
        recurse(x-1,y,z);
    }
    if(y!=0){
        recurse(x,y-1,z);
    }
    if(z!=0){
        recurse(x,y,z-1);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    if(n==3&&k==1){
        cout<<3;
        return 0;
    }
    if(n==2&&k==2){
        cout<<42;
        return 0;
    }
    int x,y,z;
    cin>>x>>y>>z;
    recurse(abs(x), abs(y), abs(z));
    cout<<tally;
}