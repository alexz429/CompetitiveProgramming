#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    bool arr[n][n];
    bool flip = 0;
    for(int i=0;i<n;i++){
        string in;
        cin>>in;
        for(int j=0;j<n;j++){
            arr[i][j] = in[j] =='R';
            if(i==0&&j==0){
                if(!arr[i][j])flip=true;
            }
            else if(j==0&&flip){
                arr[i][j] = !arr[i][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(!arr[i][0]){
            for(int j=0;j<n;j++){
                arr[i][j] = !arr[i][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(!arr[0][i]){
            for(int j=0;j<n;j++){
                arr[j][i] = !arr[j][i];
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int tally = 0;
    int x, y;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(!arr[i][j]){
                tally++;
                if(tally == 1){
                    x = i+1, y=j+1;
                }
            }
        }
    }
    if(tally==1){
        cout<<x<<" "<<y<<"\n";
        return 0;
    }
    else if(tally == (n-1)*(n-1)){
        cout<<1<<" "<<1<<"\n";
        return 0;
    }
    if(tally==n-1){
        for(int i=1;i<n;i++){
            bool flip = true;
            for(int j=1;j<n;j++){
                if(arr[j][i]){
                    flip=false;
                    break;
                }
            }
            if(flip){
                cout<<1<<" "<<i+1<<"\n";
                return 0;
            }
        }
        for(int i=1;i<n;i++){
            bool flip = true;
            for(int j=1;j<n;j++){
                if(arr[i][j]){
                    flip=false;
                    break;
                }
            }
            if(flip){
                cout<<i+1<<" "<<1<<"\n";
                return 0;
            }
        }
        cout<<-1<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
}