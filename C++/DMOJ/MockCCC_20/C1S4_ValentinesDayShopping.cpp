#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,q;
    ll b;
    cin>>n>>q>>b;
    ll vals[n];
    for(int i=0;i<n;i++){
        cin>>vals[i];
    }
    for(int i=0;i<q;i++){
        string com;
        int one,two;
        cin>>com>>one>>two;
        if(com[0]=='Q'){
            int tally = 1;
            ll sum = 0;
            one--;two--;
            bool can = true;
            for(int j=one; j<=two;j++){
                sum+=vals[j];
                if(vals[j]>b){
                    can = false;
                }
                if(sum>b){
                    sum = vals[j];
                    tally++;
                }
            }
            if(can){
                cout<<tally<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            one--;
            vals[one] = two;
        }
    }
}