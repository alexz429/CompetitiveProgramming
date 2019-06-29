#include <bits/stdc++.h>
int* stuff;
int main(){
    int max;
    scanf("%d", &max);
    int tally=0;
    stuff=new int[max];
    for(int count=0;count<max;count++){
        scanf("%d", &stuff[count]);
        tally+=stuff[count];
    }
    tally/=max;
    int temp=0;
    for(int count=0;count<max;count++){
        temp+=abs(stuff[count]-tally);
    }
    printf("%d", temp/2);
}