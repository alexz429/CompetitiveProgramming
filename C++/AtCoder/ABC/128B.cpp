#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct B
{
    int score;
    string city;
    int index;
    B(int a,const string &b, int c):score(a), city(b), index(c)
    {
        
    }
    B(){

    }
};
     bool customSort( B a, B b){
        if(a.city==b.city){
            return a.score>b.score;
        }
        return a.city.compare(b.city)<0;
        
    }


int main(){
    B* in;
    int max;
    scanf("%d", &max);
    in=new B[max];
    // printf("done");
    B test(0,"hi", 0);
    for(int count=0;count<max;count++){
        int a;
        char raw[11];
        scanf("%s %d", raw,&a);
        string b=raw;
        in[count]=B(a,b,count);
        // printf("done2");
    }
    sort(in, in+max, customSort);
    for(int count=0;count<max;count++){
        printf("%d\n", in[count].index+1);
    }
}