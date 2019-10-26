#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> stuff;
int dp[2][100000];
int main(){
    dp[0][0] = 1e9+1;
    dp[1][0] = 1e9+1;
    ifstream file;
       file.open("C:\\Users\\alex.zhang\\Desktop\\cipele.in.4a");
       if(!file){
           printf("oof");
           return 0;
       }
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int l,r;
    file>>l>>r;
    int lim = min(l,r);
    int diff = abs(l-r);
    // printf("hi");
    stuff.emplace_back(vector<int>());
    stuff.emplace_back(vector<int>());
    int index = 0;
    for(int i=0;i<l;i++){
        int next;
        file>>next;
        stuff[0].emplace_back(next);
    }
    for(int i=0;i<r;i++){
        int next;
        file>>next;
        stuff[1].emplace_back(next);
    }
    if(l>r){
        index = 1;
    }
    // printf("%d\n", index);
    sort(stuff[0].begin(), stuff[0].end());
    sort(stuff[1].begin(), stuff[1].end());
    int best=-1;
    int flip = 0;
    int pinpoint=0;
    int temp = 1;
    for(int i = 0; i < stuff[index].size();i++){
        
        for(int j=temp;j<=diff+1;j++){
            dp[flip][j] = abs(stuff[index][i]-stuff[index^1][i+j-1]);
            if(i!=0){
                dp[flip][j] = max(dp[flip][j] ,dp[flip^1][j]);
            }
            if(j!=1){
                if(dp[flip][j]<dp[flip][j-1]){
                    temp = j;
                }
                else{
                    dp[flip][j] =dp[flip][j-1];
                }
            }
            
            // printf("%d ",dp[flip][j]);
        }
        flip^=1;
        printf("%d\n", temp);
    }   
    printf("%d\n", dp[flip^1][diff+1]);
}