#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    int best = 0;
    int sum = 0;
    int small = 1000;
    for(int i=0;i<5;i++){
        int next;
        cin>>next;
        small = min(small, next);
        sum+=next;
    }
    
    best = max(best, sum-small);
    sum = 0;
    small = 1000;
    for(int i=0;i<5;i++){
        int next;
        cin>>next;
        small = min(small, next);
        sum+=next;
    }
    best = max(best, sum-small);
    cout<<best<<endl;
}