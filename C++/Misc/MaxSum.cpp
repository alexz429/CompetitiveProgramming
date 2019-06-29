#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main(){
    int max;
    scanf("%d", &max);
    int smallest=1e9+5;
    ll tally=0;
    bool kill=false;
    for(int count=0;count<max;count++){
        int next;
        scanf("%d", &next);
        tally+=abs(next);
        smallest=min(abs(next), smallest);
        if(next<0){
            kill=!kill;
        }
    }
    if(kill){
        tally-=smallest*2;
    }
    printf("%lld", tally);
}