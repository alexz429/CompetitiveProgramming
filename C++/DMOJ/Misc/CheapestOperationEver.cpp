#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int n,h;

    scanf("%d %d", &n,&h);
    int* p=new int[n+1];
    ll* dp=new ll[n+1];
    fill(&dp[0], &dp[n+1], 0x3f3f3f3f);
    dp[0]=0;
    for(int count=1;count<=n;count++){
        scanf("%d", &p[count]);
    }
    p[0]=p[1];
    int last=0;
    for(int count=1;count<=n;count++){
        for(int count2=last;count2<count;count2++){
            ll temp=dp[count2]+h+(p[count]-p[count2+1])*(p[count]-p[count2+1]);
            // printf("%lld\n", temp);
            if(temp<dp[count]){
                dp[count]=temp;
                last=count2;
                // printf("AYYY %lld\n", dp[count]);
            }
        }
    }
    printf("%d\n", dp[n]);
}