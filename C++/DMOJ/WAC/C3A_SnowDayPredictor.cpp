#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int tally = 0;
    if(a<-40){
        tally++;
    }
    if(b >= 15){
        tally++;
    }
    if(c > 50){
        tally++;
    }
    if(tally>=2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}