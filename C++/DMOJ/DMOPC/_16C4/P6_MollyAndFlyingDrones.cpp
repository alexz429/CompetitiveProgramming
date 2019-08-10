#include <bits/stdc++.h>
using namespace std;
#define ll long long
class node{
    public:
    int index;
    int value;
    node(int a, int b){
        index=a;
        value=b;
    }
};

deque<node> small;
ll psa[1000001];
int vals[1000001];
int main(){
    int n,m;
    fill(&psa[0], &psa[1000001], 0);
    scanf("%d %d", &n, &m);
    
    int* left=new int[n];
    small.emplace_front(-1,-1);
    for(int count=0;count<n;count++){
        int next;
        scanf("%d", &next);
        vals[count]=next;
        while(small.front().value>=next){
            small.pop_front();
        }
        left[count]=small.front().index+1;
        small.emplace_front(count,next);
    }
    small.clear();
    small.emplace_front(n,-1);
    for(int count=n-1;count>=0;count--){
        while(small.front().value>vals[count]){
            small.pop_front();
        }
        ll wut=count-left[count]+1;
        ll wat=small.front().index-count;
        psa[vals[count]]+=wut*wat;
        small.emplace_front(count,vals[count]);
    }
    int prev=0;
    for(int count=0;count<1000001;count++){
        prev+=psa[count];
        psa[count]=prev;
    }
    for(int count=0;count<m;count++){
        int l,r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", psa[r]-psa[l-1]);
    }
}