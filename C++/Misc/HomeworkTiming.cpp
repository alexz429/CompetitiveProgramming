#include <bits/stdc++.h>

int main(){
    int start=16511;
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    int end=a*24*60+b*60+c;
    printf("%d", end<start?-1:end-start);
}