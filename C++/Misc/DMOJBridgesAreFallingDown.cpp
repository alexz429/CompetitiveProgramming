#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll tally;
int* paths[2];
int* parents;
int* num;

int findParent(int a){
    if(parents[a]==a){
        return a;
    }
    parents[a]=findParent(parents[a]);
    return parents[a];
}

void merge(int a, int b){
    int left=findParent(a);
    int right=findParent(b);
    if(left==right){
        return;
    }
    tally-=num[left]*num[right];
    num[left]+=num[right];
    parents[right]=parents[left];
}
ll* out;
int main(){
    int nodes,edges;
    scanf("%d %d", &nodes, &edges);
    tally=((ll)nodes*((ll)nodes-1))/2;
    num=new int[nodes];
    fill(&num[0], &num[nodes], 1);
    parents=new int[nodes];
    for(int count=0;count<nodes;count++){
        parents[count]=count;
    }
    paths[0]=new int[edges];
    paths[1]=new int[edges];
    for(int count=0;count<edges;count++){
        scanf("%d %d", &paths[0][count], &paths[1][count]);
        paths[0][count]--;
        paths[1][count]--;
    }
    out=new ll[edges];
    for(int count=edges-1;count>=0;count--){
        // printf("%lld %d %d", tally, paths[0][count], paths[1][count]);
        out[count]=tally;
        merge(paths[0][count],paths[1][count]);
    }
    for(int count=0;count<edges;count++){
        printf("%lld\n", out[count]);
    }

}