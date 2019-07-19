#include <bits/stdc++.h>

using namespace std;


int hori[50001];
int verti[50001];
bool hit[400001];
int main(){
    
        fill(&hori[0], &hori[50001], 0);
        fill(&verti[0], &verti[50001], 0);
        fill(&hit[0], &hit[40001], false);
    int q;
    scanf("%d", &q);
    for(int count=0;count<q;count++){
        int n,m;
        scanf("%d %d%*c", &n, &m);
        int horiBest=0;
        int vertiBest=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char val;
                scanf("%c", &val);
                if(val=='*'){
                    hori[i]++;
                    verti[j]++;
                    hit[i*m+j]=true;
                    
                    
                }

            }
            scanf("%*c");
        }
        int best=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(hit[i*m+j]){
                    best=max(best,hori[i]+verti[j]-1);
                }
                else{

                best=max(best,hori[i]+verti[j]);
                }
            }
        }
        printf("%d\n", n+m-1-best);
        
        fill(&hori[0], &hori[n], 0);
        fill(&verti[0], &verti[m], 0);
        fill(&hit[0], &hit[n*m], false);
    }
}