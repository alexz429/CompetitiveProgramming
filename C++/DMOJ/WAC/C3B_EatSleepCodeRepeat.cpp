#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int max;
    cin>>max;
    for(int i=0;i<max;i++){
        int next;
        cin>>next;
        ll small = next/3;
        ll rem = next-(small*3);
        ll base = 1;
        for(int i=0;i<3;i++){
            if(i<rem){
                base*=small+1;
            }
            else{
                base*=small;
            }
        }
        cout<<base<<"\n";
    }
}