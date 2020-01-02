#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    map<int,int> tally;
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        if(tally.find(next) != tally.end()){
            tally[next]++;
        }
        else{
            tally[next] = 1;
        }
        cout<<tally[next]-1<<endl;
    }
    cout<<tally.size()<<endl;
}