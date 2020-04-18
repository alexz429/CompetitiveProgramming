#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int BIT[n+1];
    fill(&BIT[0], &BIT[n+1], 0);
    for(int i=0;i<n;i++){
        int index = i+1;
        while(index<n){
            BIT[index] += input[i];
            index = index+(-index);
        }
    }
}