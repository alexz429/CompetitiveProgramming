#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        int tally = 0;
        while(next>0){
            int mod = 1;
            while(mod*10<=next){
                mod*=10;
            }
            int add = next/mod;
            next%=mod;
            next+=add*(mod/10);
            // cout<<add<<endl;
            tally+=add*mod;
            // cout<<next<<" ";
        }
        cout<<tally<<"\n";
    }
}