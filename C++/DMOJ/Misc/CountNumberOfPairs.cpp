#include <bits/stdc++.h>
using namespace std;
#define ll long long
int* numbers;
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    numbers=new int[n];
    for(int count=0;count<n;count++){
        scanf("%d", &numbers[count]);
    }
    sort(&numbers[0], &numbers[n]);
    int top=n-1;
    ll tally=0;
    for(int count=0;count<top&&count<n;count++){
        while(numbers[count]+numbers[top]>m){
            top--;
        }
        if(top<count)break;
        tally+=top-count;
    }
    printf("%lld\n", tally);
}