#include <bits/stdc++.h>

using namespace std;
int* vals;
int* front;
int* back;
int gcd(int a, int b){
    if(a==0)return b;
    return gcd(b%a,a);
}
int main(){
    int max;
    scanf("%d", &max);
    vals=new int[max];
    front=new int[max];
    back=new int[max];
    int cur=-1;
    for(int count=0;count<max;count++){
        scanf("%d", &vals[count]);
        if(cur==-1){
            cur=vals[count];
        }
        else{
            cur=gcd(cur, vals[count]);
        }
        front[count]=cur;

    }
    cur=-1;
    for(int count=max-1;count>=0;count--){
        if(cur==-1){
            cur=vals[count];
        }
        else{
            cur=gcd(cur, vals[count]);
        }
        back[count]=cur;
    }
    int best=0;
    for(int count=0;count<max;count++){
        int target;
        if(count==0){
            target=back[count+1];
        }
        else if(count==max-1){
            target=front[max-2];
        }
        else{
            target=gcd(front[count-1],back[count+1]);
        }
        best=std::max(best,target);
    }
    printf("%d", best);
    
}