#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool seg[500008];
void add(int at, int l, int r, int min, int max){
    if(r<min||l>max)return;
    if(l>=min&&r<=max){
        seg[at]=!seg[at];
        return;
    }
    int mid = (l+r)/2;
    add(at*2, l, mid, min, max);
    add(at*2+1, mid+1, r, min, max);
}
bool query(int at, int l, int r, int min, int max){
    if(r<min||l>max)return false;
    if(l>=min&&r<=max){
        return seg[at];
    }
    int mid = (l+r)/2;
    return seg[at]^(query(at*2, l, mid, min, max)||query(at*2+1, mid+1, r, min, max));
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    int prev= -1;
    int index = 0;
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        switch(next){
            case 1:
            add(1,0,n,index,index);
            prev = index++;
            break;
            case 2:
            add(1,0,n, prev, index++);
            break;
            case 3:
            int lol;
            cin>>lol;
            cout<<(query(1, 0, n, lol-1, lol-1)?1:0)<<"\n";
        }
    }
}