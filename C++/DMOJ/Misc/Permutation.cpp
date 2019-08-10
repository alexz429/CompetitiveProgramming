#include <bits/stdc++.h>
typedef long long ll;
ll psa[2][3001];
bool states[3001];
int main(){
    int max;
    scanf("%d", &max);
    scanf("%*c");
    for(int count=0;count<max;count++){
        char next;
        scanf("%c", &next);
        // printf("%c", next);
        states[count+1]=(next=='>');
    }
    int cur=0;
    std::fill(&psa[1][1], &psa[1][max+1], 1);
    for(int count=2;count<=max;count++){
        for(int count2=1;count2<=count;count2++){
            if(!states[count-1]){
                // printf("hi ");
                psa[cur][count2]=psa[cur^1][count2-1];
                psa[cur][count2]+=psa[cur][count2-1];
            }
            else{
                psa[cur][count2]=psa[cur^1][max]-psa[cur^1][count2-1];
                psa[cur][count2]+=psa[cur][count2-1];
            }
            psa[cur][count2]+=(int)(1e9+7);
            psa[cur][count2]%=(int)(1e9+7);
            psa[cur][max]=psa[cur][count2];
            
            // printf("%lld ", psa[count][count2]);
        }
        cur^=1;
        // printf("\n");
    }
    printf("%lld\n", psa[cur^1][max]);
}