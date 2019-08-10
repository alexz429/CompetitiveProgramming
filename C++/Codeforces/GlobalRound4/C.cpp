#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int w,h;
    scanf("%d %d", &w, &h);
    ll start=4;
    for(int count=0;count<w+h-2;count++){
        start*=2;
        start%=998244353;
    }
    printf("%lld\n", start);
}