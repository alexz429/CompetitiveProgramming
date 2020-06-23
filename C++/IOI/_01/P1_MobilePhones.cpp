#include <bits/stdc++.h>
using namespace std;
// typedef long long int;
#define LIMIT 1024

int seg[LIMIT+1][LIMIT+1];
int n;
int getSum(int x, int y){
    int sum = 0;
    while(x>0){
        int temp = y;
        while(temp>0){
            sum+=seg[x][temp];
            temp-=(temp&-temp);
        }
        x-=(x&-x);
    }
    return sum;
}
int query(int x1, int x2, int y1, int y2){
    return getSum(x2,y2) - getSum(x1-1, y2)- getSum(x2, y1-1) + getSum(x1-1,y1-1);
}
void insert(int x, int y, int val){
    while(x<=n){
        int temp = y;
        while(temp<=n){
            seg[x][temp] += val;
            temp+=(temp&-temp);
        }
        x+=(x&-x);
    }
}
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int com;
    cin>>com>>n;
    cin>>com;
    while(com!=3){
        if(com==1){
            int x,y,v;
            cin>>x>>y>>v;
            insert(x+1,y+1,v);
            // for(int i=1;i<=10;i++){
            //     for(int j=1;j<=10;j++){
            //         cout<<seg[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
        }
        else{
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            cout<<query(x1+1,x2+1,y1+1,y2+1)<<endl;
        }
        cin>>com;
    }

}