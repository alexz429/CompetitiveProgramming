#include <bits/stdc++.h>

using namespace std;
class segment{
    public:
    int index;
    int comp;
    int other;
    segment(){

    }
    
    
};
inline bool sorter(segment a, segment b){
    return a.comp<b.comp;
}
segment* input;
segment* removal;
int main(){
    set<int> avail;
    
    int N,Q;
    scanf("%d %d", &N, &Q);
    input=new segment[N];
    removal=new segment[N];
    for(int count=0;count<N;count++){
        int from, to, at;
        scanf("%d %d %d", &from, &to, &at);
        from-=at;
        to-=at;
        input[count].index=at;
        removal[count].index=at;
        input[count].comp=from;
        input[count].other=to;
        removal[count].comp=to;
    }
    sort(&input[0], &input[N], sorter);
    sort(&removal[0], &removal[N], sorter);
    int at=0;
    int at2=0;
    for(int count=0;count<Q;count++){
        int next;
        scanf("%d", &next);
        while(at2<N&&removal[at2].comp<=next){
            avail.erase(removal[at2].index);
            // printf("removed %d\n", removal[at2].index);
            at2++;
        }
        while(at<N&&input[at].comp<=next){
            if(input[at].other>next){
                
            avail.insert(input[at].index);
            }
            // printf("added %d\n", input[at].index);
            at++;
        }
        
        if(avail.empty()){
            printf("-1\n");
        }
        else{

        printf("%d\n",*avail.begin());
        }
    }

}