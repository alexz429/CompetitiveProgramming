#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    for(int j=0;j<10;j++){
        int n,m,d;
    cin>>n>>m>>d;
    int shirts[d];
    fill(&shirts[0], &shirts[d], 0);
    vector<int> list;
    for(int i=0;i<m;i++){
        int next;
        cin>>next;
        shirts[next-1]++;
    }
    sort(list.begin(), list.end());
    int ptr=0;
    int out = 0;
    int temp = n;
    for(int i=0;i<d;i++){
        if(temp==0){
            out++;
            temp = n;
        }
        temp--;
        temp+=shirts[i];
        n+=shirts[i];
    }
    cout<<out<<endl;
    }
    
}