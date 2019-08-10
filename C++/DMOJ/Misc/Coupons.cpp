#include <bits/stdc++.h>
#define ll long long

using namespace std;
int* books;
int* alt;
int main(){
    /*
    sorted set of sorted normal costs and coupon costs
    
     */
    int n,k;
    ll m;
    scanf("%d %d %lld", &n, &k,&m);
    books=new int[n];
    alt=new int[n];
    for(int count=0;count<n;count++){
        scanf("%d %d", &books[count], &alt[count]);
    }
    sort(books, books+n);
    sort(alt,alt+n);
    
}