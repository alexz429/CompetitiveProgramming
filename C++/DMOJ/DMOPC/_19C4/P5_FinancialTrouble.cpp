#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int events[2000];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,q;
    ll m;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        cin>>events[i];
    }
    for(int i=0;i<q;i++){
        int start, end;
        cin>>start>>end;
        ll temp = m;
        int count=0;
        for(int j=start-1;j<end;j++){
            temp+=events[j];
            if(temp<0){
                temp=0;
                count++;
            }
        }
        cout<<temp<<" "<<count<<endl;
    }
}