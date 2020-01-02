#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string a,b;
    cin>>a>>b;
    int diff = 0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]){
            diff++;
        }
    }
    if(diff!=1){
        cout<<"LARRY IS DEAD!"<<endl;
    }
    else{
        cout<<"LARRY IS SAVED!"<<endl;
    }
}