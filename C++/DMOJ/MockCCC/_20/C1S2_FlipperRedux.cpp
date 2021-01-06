#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    bool grid[n][n];
    bool flip = 0;
    queue<string> output;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(i==0&&j==0){
                if(grid[i][j]){
                    flip = true;
                    output.push("R 1");
                }
            }
            if(i==0&&flip){
                grid[i][j] = !grid[i][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(grid[i][0]){
            string next = "R "+to_string(i+1);
            output.push(next);
            for(int j=0;j<n;j++){
                grid[i][j]=!grid[i][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(grid[0][i]){
            string next = "C "+to_string(i+1);
            output.push(next);
            for(int j=0;j<n;j++){
                grid[j][i]=!grid[j][i];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]){
                cout<<"-1"<<"\n";
                return 0;
            }
        }
    }
    cout<<output.size()<<"\n";
    while(output.size()>0){
        cout<<output.front()<<"\n";
        output.pop();
    }
}