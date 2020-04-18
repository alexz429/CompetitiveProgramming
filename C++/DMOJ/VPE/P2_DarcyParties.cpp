#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    int val[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>val[i];
        sum+=val[i];
    }
    int ans = sum/n;
    int tally = 0;
    for(int i=0;i<n;i++){
        if(val[i]!=ans){
            tally++;
        }
    }
    cout<<tally<<endl;
}
