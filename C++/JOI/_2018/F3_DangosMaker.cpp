#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char grid[3000][3000];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    for(int i=0;i<n;i++){
        string next;
        cin>>next;
        for(int j=0;j<m;j++){
            grid[i][j] = next[j];
        }
    }
    
}