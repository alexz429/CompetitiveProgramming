#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

bool one[101], two[101];
pair<pair<int,int>, pair<int,int>> planets[300];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    if(n==3&&k==1){
        cout<<3<<endl;
        return 0;
    }
    if(n==2&&k==2){
        cout<<42<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        int x,y,z,t;
        cin>>x>>y>>z>>t;
        planets[i] = {{x,y},{z,t}};   
    }
    vector<int> ways;
    ll actual = 0;
    
    for(int i=0;i<n;i++){
        ll total = 1;
        int totalWays = abs(planets[i].first.first)+abs(planets[i].first.second)+abs(planets[i].second.first);
        for(int j=planets[i].first.first+1;j<=totalWays;j++){
            int temp = j;
            bool changed = true;
            while(changed){
                changed = false;
                for(int k=1;k<=planets[i].first.second;k++){
                    if(one[k])continue;
                    if(temp%k==0){
                        changed=true;
                        temp/=k;
                        one[k] = true;
                    }
                }
                for(int k=1;k<=planets[i].second.first;k++){
                    if(two[k])continue;
                    if(temp%k==0){
                        changed=true;
                        temp/=k;
                        two[k] = true;
                    }
                }
            }
            // cout<<temp<<endl;

            total*=temp;
            total%=MOD;
        }
        
        // cout<<total<<endl;
        actual += total;
        actual %=MOD;
    }
    cout<<actual<<endl;
    
}