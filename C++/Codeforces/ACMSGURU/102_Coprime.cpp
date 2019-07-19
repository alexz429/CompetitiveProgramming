#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b){
    // printf("%d %d\n", a, b);
    if(a==0)return b;
    return gcd(b%a,a);
}
int main(){ 
    int N;
    scanf("%d", &N);
    int tally=0;
    for(int count=1;count<=N;count++){
        // printf("%d\n", count);
        if(gcd(count,N)==1){
            tally++;
        }
    }
    printf("%d",tally);
}