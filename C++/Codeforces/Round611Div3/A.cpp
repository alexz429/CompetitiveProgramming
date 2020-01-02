#include <bits/stdc++.h>
using namespace std;

int main(){
    int max;
    cin>>max;
    int comp = 24*60;
    for(int i=0;i<max;i++){
        int a,b;
        cin>>a>>b;
        int lol = a*60+b;
        cout<<(comp-lol)<<endl;
    }
}