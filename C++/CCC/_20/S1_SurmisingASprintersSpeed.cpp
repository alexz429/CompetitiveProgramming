#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    pair<int,int> vals[n];

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vals[i] = {a,b}; 
    }
    sort(&vals[0], &vals[n]);
    double best = 0;
    for(int i=1;i<n;i++){
        best =max(best, (double)abs(vals[i-1].second-vals[i].second)/(double)(vals[i].first-vals[i-1].first));
    }
    cout<<fixed<<setprecision(10)<<best<<endl;
}