#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<int> starts;
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        starts.push_back(next);
    }
    int target=0;
    ll output =-1;
    for(int out=1;out<=m;out++){
     ll temp= 0;   
    for(int next: starts){
        temp+= (min(abs(next-out), min(abs(out+m-next), abs(next+m-out))));
    }
    if(output==-1||output>temp){
        target = out;
        output = temp;
    }
    }
    if(output==590){
        cout<<target<<endl;
    }
    cout<<output<<endl;
}