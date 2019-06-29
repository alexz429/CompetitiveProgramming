#include <bits/stdc++.h>

#define ll long long
int* in;
int main(){
    int max;
    scanf("%d", &max);
    in=new int[max];
    for(int count=0;count<max;count++){
        scanf("%d", &in[count]);
    }
    ll tally=0;
    for(int count=0;count<max;count++){
        int next;
        scanf("%d", &next);
        if(next<in[count]){
            tally+=in[count]-next;
        }
    }
    printf("%d", tally);
}