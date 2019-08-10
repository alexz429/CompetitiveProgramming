#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string in;
    cin>>in;
    ll total=0;
    bool prev=false;
    for(int count=0;count<in.length();count++){
        if(in[count]=='v'){
            if(prev){
                total++;
            }
            prev=true;
        }
        else{
            prev=false;
        }
    }
    ll tally=0;
    ll output=0;
    prev=false;
    for(int count=0;count<in.length();count++){
        if(in[count]=='v'){
            if(prev){
                tally++;
            }
            prev=true;
        }
        else{
            output+=tally*(total-tally);
            prev=false;
        }

    }
    printf("%lld\n", output);
}