#include <bits/stdc++.h>
using namespace std;
bool visited[101];
int ds[7];
int findParent(int a){
    if(ds[a]==a)return a;
    ds[a]=findParent(ds[a]);
    return ds[a];
}
void join(int a, int b){
    ds[findParent(a)]=findParent(b);
}
class path{
    public:
    int end;
    int index;
    int side;
    path(int a, int b, int c){
        end=a, index=b,side=c;
    }
};
vector<path> direct[7];
void recurse(path at){
    if(visited[at.index])return;
    visited[at.index]=true;
    for(path next: direct[at.end]){
        recurse(next);
    }
    printf("%d %c\n", at.index, at.side==1?'-':'+');
}
int main(){
    int N;
    scanf("%d", &N);
    int connects[7];
    fill(&connects[0], &connects[7], 0);
    for(int count=0;count<7;count++){
        ds[count]=count;
}
    for(int count=0;count<N;count++){
        int from,to;
        scanf("%d %d", &from, &to);
        
        join(from, to);
        
        connects[from]++;
        connects[to]++;
        direct[from].emplace_back(to,count+1,1);
        direct[to].emplace_back(from,count+1,0);
    }
    int prev=-1;
    int start=-1;
    bool lock=false;
    int numOdds=0;
    for(int count=0;count<7;count++){
        if(connects[count]>0){
            // printf("%d\n", ds[count]);
            if(prev!=-1&&findParent(ds[count])!=prev){
                printf("No solution");
                return 0;
            }
            prev=findParent(ds[count]);
            if(connects[count]%2==1){
                numOdds++;
                if(numOdds>2){
                    printf("No solution");
                    return 0;
                }
                start=count;
                lock=true;
            }
            if(lock!=true){
                start=count;
            }
        }
    }
    // printf("%d\n", start);
    for(path next: direct[start]){
        recurse(next);
    }
}