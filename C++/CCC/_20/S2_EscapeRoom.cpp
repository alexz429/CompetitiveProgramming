#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int m,n;
bool hit[1000][1000];
int arr[1000][1000];
bool recurse(int x,int y){
    if(x<0||x>m-1||y<0||y>n-1||hit[x][y])return false;
    hit[x][y] = true;
    if(x==m-1&&y==n-1)return true;
    
    int val = arr[x][y];
    for(int i=1;i<sqrt(val)+1;i++){
        if(val%i==0){
            if(recurse(i-1,val/i-1))return true;
            if(recurse(val/i-1,i-1))return true;
        }
    }
    return false;
    
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    if(recurse(0,0)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}