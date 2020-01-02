#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int most;
    cin>>most;
    for(int i=0;i<most;i++){
        int a,b;
        cin>>a>>b;
        int lim = a%b;
        int layer = a/b;
        lim= min(lim, b/2);
        cout<<(layer*b+lim)<<endl;
    }
}