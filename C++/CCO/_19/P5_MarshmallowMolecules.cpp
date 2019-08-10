#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<int> *yeet;
int main(){
    
    int n,m;
    scanf("%d %d", &n, &m);
    yeet=new set<int>[n];
    for(int count=0;count<m;count++){
        int from,to;
        scanf("%d %d", &from,&to);
        yeet[min(--from,--to)].insert(max(from,to));
    }
    ll tally=0;
    for(int count=0;count<n;count++){
        tally+=yeet[count].size();
        // printf("%d\n", tally);
        if(yeet[count].size()==0)continue;
        int target=*yeet[count].begin();
        yeet[count].erase(yeet[count].begin());
        if(yeet[target].size()<yeet[count].size()){
            swap(yeet[target], yeet[count]);
        }
        for(int next:yeet[count]){
                yeet[target].insert(next);
        }

    }
    printf("%lld\n", tally);
}
