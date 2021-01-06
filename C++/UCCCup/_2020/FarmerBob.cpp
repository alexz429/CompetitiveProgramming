#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int hay;
    cin>>hay;
    int trac;
    cin>>trac;
    int sizes[trac];
    for(int i=0;i<trac;i++){
        cin>>sizes[i];
    }
    int field;
    cin>>field;
    int streak = 0;
    int best = 0;
    string next;
    cin>>next;
    for(int i=0;i<field;i++){
        if(next[i]=='1'){
            streak= 0;
        }
        else{
            streak++;
            best = max(best, streak);
        }
    }
    int big = 0;
    for(int i=0;i<trac;i++){
        if(sizes[i]<=best){
            big = sizes[i];
        }
    }
    cout<<(hay/big+(hay%big!=0))<<endl;
}