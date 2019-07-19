#include <bits/stdc++.h>
using namespace std;
int* ds;
int findParent(int a){
    if(ds[a]==a)return a;
    ds[a]=findParent(ds[a]);
    return ds[a];
}
void merge(int a, int b){
    ds[findParent(a)]=findParent(b);
}
bool* found;
int main(){
    int N,M,K;
    scanf("%d %d %d", &N, &M, &K);
    found=new bool[N];
    fill(&found[0], &found[N], false);
    ds=new int[N];
    for(int count=0;count<N;count++){
        ds[count]=count;
    }
    for(int count=0;count<M;count++){
        int from, to;
        scanf("%d %d", &from, &to);
        from--,to--;
        merge(from,to);
    }
    int regions=0;
    for(int count=0;count<N;count++){
    
        if(found[findParent(count)])continue;
        found[findParent(count)]=true;
        regions++;
    }
    // printf("%d\n", regions);
    int waste=M-(N-regions);
    printf("%d\n", max(0,(regions-1-min(waste,K))));
}