#include <bits/stdc++.h>
using namespace std;
int sums[1414215];
int main(){
    int houses, scenarios;
    scanf("%d %d", &houses, &scenarios);
    fill(&sums[0], &sums[1414215],0);
    for(int count=0;count<houses;count++){
        int x,y;
        scanf("%d %d", &x, &y);
        double location=sqrt(pow(x,2)+pow(y,2));
        sums[(int)ceil(location)]++;

    }
    int cur=0;
    for(int count=0;count<1414215;count++){
        cur+=sums[count];
        sums[count]=cur;
    }
    for(int count=0;count<scenarios;count++){
        int r;
        scanf("%d",&r);
        printf("%d\n", sums[r]);
    }
}