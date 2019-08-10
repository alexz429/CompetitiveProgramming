#include <bits/stdc++.h>
using namespace std;
int psa[10001];
int psa2[10001];
int dp[10001];
int batchNum[10001];
int main(){
    int max, wait;
    scanf("%d", &max);
    scanf("%d", &wait);
    for(int count=1;count<=max;count++){
        scanf("%d %d", &psa[count], &psa2[count]);
        psa[count]+=psa[count-1];
        psa2[count]+=psa2[count-1];
    }
    
    for(int count=1;count<=max;count++){
        dp[count]=100000000;
        for(int i=1;i<=count;i++){
            int val=dp[i-1]+(psa[count]+wait*(batchNum[i-1]+1))*(psa2[count]-psa2[i-1]);
            if(dp[count]>val||(dp[count]==val&&batchNum[i-1]+1<batchNum[count])){
                batchNum[count]=batchNum[i-1]+1;
            dp[count]=val;
            }
        }
        printf("%d %d\n", dp[count], batchNum[count]);
    }
    printf("%d\n", dp[max]);
}