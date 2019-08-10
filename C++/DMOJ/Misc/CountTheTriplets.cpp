#include <bits/stdc++.h>
using namespace std;
int exist[1000001];
int main(){
    int n;
    scanf("%d", &n);
    vector<int> vals(n);
    fill(&exist[0], &exist[1000001], 0);
    for(int count=0;count<n;count++){
        int next;
        scanf("%d", &next);
        if(exist[next]){
            exist[next]++;   
            continue;
         }
          exist[next]++;
        vals[count]=next;
        
    }
    sort(&vals[0], &vals[n]);
    int tally=0;
    for(int count=0;count<vals.size();count++){
        if(vals[count]==0)continue;
        // printf("%d_____\n", vals[count]);
        for(int i=count+1;i<vals.size();i++){
            int key=vals[i]-vals[count];
            if(exist[key]){
                if(key>vals[count]){
                    tally++;
                }
                else if(key==vals[count]&&exist[vals[count]]>1){
                    tally++;
                }
            }
        }
    }
    printf("%d\n", tally==0?-1:tally);
}