#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> stuff;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int grid[n][n];
        int rows = 0;
        for(int j=0;j<n;j++){
            int add = 1;
            for(int k=0;k<n;k++){
                cin>>grid[j][k];
                if(stuff.find(grid[j][k])!=stuff.end()){
                    rows+=add;
                    add=0;
                }
                stuff.insert(grid[j][k]);
            }
            stuff.clear();
            add = 1;
        }
        int trace = 0;
        for(int j=0;j<n;j++){
            trace+=grid[j][j];
        }
        int col = 0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(stuff.find(grid[k][j])!=stuff.end()){
                    col++;
                    break;
                }
                stuff.insert(grid[k][j]);
            }
            stuff.clear();
        }
        cout<<"Case #"<<i+1<<": "<<trace<<" "<<rows<<" "<<col<<endl;
    }
}