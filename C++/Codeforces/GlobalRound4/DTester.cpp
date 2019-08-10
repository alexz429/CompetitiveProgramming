#include <bits/stdc++.h>
using namespace std;
bool* sieve;

int main(){
    int in=1000;
    // scanf("%d", &in);
    // printf("%d\n", in);
    int limit=(in*(in-1))/2;
    // printf("%d\n", limit);
    sieve=new bool[limit+1];
    fill(&sieve[0], &sieve[limit+1], false);
    sieve[0]=false;
    sieve[1]=false;
    for(int count=2;count<=limit;count++){
        // printf("%d\n", count);
        if(!sieve[count]){
            int fill=count+count;
            while(fill<=limit){
                sieve[fill]=true;
                fill+=count;
            }
        }
    }
    for(int count2=3;count2<=1000;count2++){
        for(int count=count2;count<=limit;count++){
        if(!sieve[count]){
            printf("%d\n", count);
            for(int i=1;i<=in;i++){
                if(i==in){
                    // printf("%d %d\n", in,1);

                }
                else{
                    // printf("%d %d\n", i,i+1);
                }
            }
            for(int i=1;i<=(count-in);i++){
                if(i+in/2>in){
                    printf("WARNING! %d", count2);
                    return 0;
                }
                // printf("%d %d\n", i,i+(in/2));
            }
            // return 0;
            break;
        }
    }
    }
    
}