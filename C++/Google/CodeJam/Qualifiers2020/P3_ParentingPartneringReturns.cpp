#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": ";
        int n;
        cin>>n;
        pair<int,pair<int,int>> chores[n];
        for(int j=0;j<n;j++){
            int a,b;
            cin>>a>>b;
            chores[j] = {a,{b,j}};
        } 
        sort(&chores[0], &chores[n]);
        char output[n];
        int left=0, right=0;
        bool lol = true;
        for(int j=0;j<n;j++){
            if(left<=chores[j].first){
                left = chores[j].second.first;
                output[chores[j].second.second]='C';
            }
            else if(right<=chores[j].first){
                right = chores[j].second.first;
                 output[chores[j].second.second]='J';
            }
            else{
                cout<<"IMPOSSIBLE"<<endl;
                lol=false;
                break;
            }
        }
        if(lol){
           for(int j=0;j<n;j++){
               cout<<output[j];
           }
           cout<<endl;
        }
    }
}