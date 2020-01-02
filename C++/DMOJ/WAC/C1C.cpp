#include <bits/stdc++.h>
//NOT DONE
using namespace std;
bool* has;
int* most;
vector<int>* direct;

void prep(int at){
    // printf("AT %d\n", at);
    if(direct[at].size()==0){
        most[at]=1;
        return;
    }
    int best=0;
    for(int next:direct[at]){
        prep(next);
        best=max(best,most[next]);

    }
    most[at]=best+1;
}
void pick(int at){
    if(direct[at].size()==0){
        most[at]=0;
        return;
    }
    int best=-1;
    int index=-1;
    for(int next:direct[at]){
        if(best<most[next]){
            best=most[next];
            index=next;
        }
    }
    pick(index);
    if(at==0)return;
    for(int next:direct[at]){
        if(next!=index){
            direct[0].push_back(next);
        }
    }
    most[at]=0;
}
int main(){
    int N,M,K;
    scanf("%d %d %d", &N, &M, &K);
    direct=new vector<int>[N];
    most=new int[N];
    
    for(int count=0;count<N-1;count++){
        int from;
        scanf("%d", &from);
        from--;
        direct[from].push_back(count+1);
    }
    prep(0);
    int *ans=new int[K];
    for(int count=0;count<M&&count<K;count++){
        ans[count]=most[0];
        pick(0);
        most[0]=0;
        for(int next:direct[0]){
            most[0]=max(most[0], most[next]);
        }
    }
    bool first=true;
    for(int count=0;count<M;count++){
        if(!first)printf(" ");
        first=false;
        printf("%d", ans[count%K]);
    }
    printf("\n");

}