#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char grid[375][80];
char commands[30000];
int r,c,m;
void process(int x,int y,int dir){
    int tx=x, ty=y;
    for(int i=0;i<m;i++){
        if(commands[i]=='R'){
            dir = (dir+1)%4;
        }
        else if(commands[i] == 'L'){
            dir = (dir+3)%4;
        }
        else{
            if(dir==0){
                ty++;
            }
            else if(dir==1){
                tx++;
            }
            else if(dir==2){
                ty--;
            }
            else{
                tx--;
            }
            if(tx<0||ty<0||tx>=r||ty>=c||grid[tx][ty]=='X'){
                return;
            }
        }
    }
    grid[tx][ty] = '*';
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        string next;
        cin>>next;
        for(int j=0;j<c;j++){
            grid[i][j] = next[j];
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        string next;
        cin>>next;
        commands[i] = next[0];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]=='X')continue;
            for(int k=0;k<4;k++){
                process(i,j,k);
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}