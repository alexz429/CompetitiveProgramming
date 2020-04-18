#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int tally = 0;
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        if(next>0){
            tally++;
        }
    }
    cout<<tally<<"\n";
}