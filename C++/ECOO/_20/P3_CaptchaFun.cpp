#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int w,h;cin>>w>>h;
            bool grid[w][h];
            pair<int,int> smaller = {1000,1000};
            pair<int,int> bigger = {-1,-1};
            for(int k=0;k<w;k++){
                string next;
                cin>>next;
                for(int l=0;l<h;l++){
                    grid[k][l] = next[l]=='*';
                    if(grid[k][l]){
                        smaller = {min(smaller.first, k), min(smaller.second, l)};
                        bigger = {max(bigger.first, k), max(bigger.second, l)};
                    }
                }
            }
            // cout<<smaller.first<<" "<<smaller.second<<" "<<bigger.first<<" "<<bigger.second<<endl;
            if(smaller.second == bigger.second){
                    cout<<"1";
                }
                else if(grid[smaller.first][smaller.second] && grid[smaller.first][bigger.second]){
                    cout<<"4";
                }
                else if(grid[bigger.first][bigger.second]){
                    cout<<"7";
                }
                else if(!grid[(smaller.first+bigger.first)/2][bigger.second-1]){
                    cout<<"0";
                }
                else{
                    bool pres[4];
                    pres[0] = grid[smaller.first+1][smaller.second];
                    pres[1] = grid[smaller.first+1][bigger.second];
                    pres[2] = grid[bigger.first-1][smaller.second];
                    pres[3] = grid[bigger.first-1][bigger.second];
                    if(pres[0]&&pres[1]&&pres[2]&&pres[3]){
                        cout<<"8";
                    }
                    else if(pres[0]&&pres[1]&&pres[3]){
                        cout<<"9";
                    }
                    else if(pres[0]&&pres[2]&&pres[3]){
                        cout<<"6";
                    }
                    else if(pres[0]&&pres[3]){
                        cout<<"5";
                    }
                    else if(pres[1]&&pres[3]){
                        cout<<"3";
                    }
                    else{
                        cout<<"2";
                    }
                }
        }
        cout<<"\n";
    }
}