#include <bits/stdc++.h>
using namespace std;
#define long long ll;
int n, init[2505], num[2505]; vector<int> adj[2505];
void recurse(int at, int prev){
    num[at] = init[at];
    for(int next: adj[at]){
        if(next==prev)continue;
        recurse(next, at);
        num[at] = (num[at]+12-num[next])%12;
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>init[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int tally = 0;
    for(int i=0;i<n;i++){
        recurse(i,-1);
        if(num[i]%12==0||num[i]%12==1){
            tally++;
        }
    }
    cout<<tally<<"\n";
}