#include <bits/stdc++.h>
#define ll long long
int* flowers;
int* vals;
ll* dp;
int* back;
using namespace std;
int main(){
    int f,max;
    scanf("%d %d", &f, &max);
    flowers=new int[f];
    vals=new int[max];
    back=new int[max];
    for(int count=0;count<f;count++){
        scanf("%d", &flowers[count]);
    }
    sort(&flowers[0], &flowers[f]);
    for(int count=0;count<max;count++){
        scanf("%d", &vals[count]);
    }
    for(int count=max-1;count>=0;count--){
        if(count==max-1){
            back[count]=vals[count];
        }
        else{
            back[count]=min(vals[count], back[count+1]);
        }
        // printf("%d\n", back[count]);
    }
    dp=new ll[f];
    for(int count=0;count<f;count++){
        dp[count]=10e13;
        for(int count2=count;count2>=0;count2--){
            if(count2==0){
                dp[count]=min(dp[count], (ll)back[flowers[count]-flowers[count2]]);
                // printf("%d %d ", back[flowers[count]-flowers[count2]], flowers[count]-flowers[count2]);
            }
            else{
                dp[count]=min(dp[count], dp[count2-1]+back[flowers[count]-flowers[count2]]);
            }
            // printf("%d %lld\n",count2, dp[count]);
        }
        // printf("%lld------------------\n", dp[count]);
    }
    printf("%lld\n", dp[f-1]);
}