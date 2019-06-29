#include <bits/stdc++.h>

using namespace std;

int* vals;
int l[51][101];
int r[51][101];
int main(){// let dp[a][k] be the maximum value obtained from (left or right) by taking a items and then dropping k of them
    int n,k;
    scanf("%d %d", &n,&k);
    vals=new int[n];
    for(int count=0;count<n;count++){
        scanf("%d", &vals[count]);
    }
    priority_queue<int, vector<int>,greater<int>> temp;
    queue<int> taken;
    for(int count=0;count<51;count++){
        fill(&l[count][0], &l[count][101], 0);
        fill(&r[count][0], &r[count][101], 0);
    }
    int val=0;
    for(int count=0;count<n;count++){
        // printf("%d %u\n", count, temp.size());
        temp.push(vals[count]);
        val+=vals[count];
        int val2=val;
        l[count+1][0]=val;
        for(int count2=0;count2+count+2<=k;count2++){
            if(temp.empty()){
                
                fill(&l[count+1][count2+1], &l[count+1][k-count-1], val2);
                break;
            }
            int next=temp.top();
            if(next<0){
            temp.pop();
            val2-=next;
            taken.push(next);
            }
            else{
                fill(&l[count+1][count2+1], &l[count+1][k-count-1], val2);
                break;
            }
            l[count+1][count2+1]=val2;
        }
        // for(int count2=0;count2<=k-count-1;count2++){
        //     printf("%d ",l[count+1][count2]);
        // }
        while(!taken.empty()){
            // printf("%d huh", next);
            temp.push(taken.front());
            taken.pop();
        }
        // printf("\n");
    }
    // printf("___________________\n");

    val=0;
    while(!temp.empty()){
        temp.pop();
    }
    for(int count=0;count<n;count++){
        temp.push(vals[n-count-1]);
        val+=vals[n-1-count];
        int val2=val;
        
        r[count+1][0]=val;
        for(int count2=0;count2+count+2<=k;count2++){
        
           if(temp.empty()){
                
                fill(&r[count+1][count2+1], &r[count+1][k-count-1], val2);
                break;
            }
            int next=temp.top();
            if(next<0){
            temp.pop();
            val2-=next;
            taken.push(next);
            }
            else{
                fill(&r[count+1][count2+1], &r[count+1][k-count], val2);
                break;
            }
            r[count+1][count2+1]=val2;
        }
        // for(int count2=0;count2<=k-count-1;count2++){
        //     printf("%d ",r[count+1][count2]);
        // }
        
        while(!taken.empty()){
            // printf("%d huh", next);
            temp.push(taken.front());
            taken.pop();
        }
        // printf("\n");
    }
    int out=0;
    for(int count=0;count<=n;count++){
        for(int count2=0;count2+count<=k;count2++){
            int rem=k-count2-count;
            for(int count3=0;count3+count<=n&&count3<=rem;count3++){
                // printf("attempt %d %d %d %d %d\n", l[count][count2], r[count3][rem-count3], count, count2, count3);
                out=max(out,l[count][count2]+ r[count3][rem-count3]);
            }
        }
    }
    printf("%d", out);
}