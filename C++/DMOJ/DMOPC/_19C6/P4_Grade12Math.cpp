#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int commands[5000000][4];
int arr[5000000];
map<int, vector<pair<int,pair<int,int>>>> lol;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>commands[i][0];
        if(commands[i][0]!=3){
            cin>>commands[i][1];
        }
        else{
            cin>>commands[i][1];
            cin>>commands[i][2];
            cin>>commands[i][3];
            if(lol.find(commands[i][3])==lol.end()){
                lol[commands[i][3]] = vector<pair<int,pair<int,int>>>();
            }
            lol[commands[i][3]].push_back({0,{commands[i][1], commands[i][2]}});
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c,d;
        a=commands[i][0];
        b=commands[i][1]-1;
        switch(a){
            case 1:
            if(lol.find(arr[b])!=lol.end());
            arr[b]++;
            break;
            case 2:
            arr[b]--;
            break;
            case 3:
            c=commands[i][2]-1;
            d=commands[i][3];
            int tally = 0;
            for(int j=b-1;j<=c-1;j++){
                // cout<<arr[j]<<" ";
                if(arr[j]==d){
                    tally++;
                }
            }
            cout<<tally<<"\n";
        }
    }
}