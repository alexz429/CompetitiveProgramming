#include <bits/stdc++.h>
using namespace std;
int m,n,q;
int arr[200001];
int seg[800001];
int prop[800001];

int add(int a, int b){
    return (a%m+b%m)%m;
}
int multi(int a, int b){
    return ((a%m)*(b%m))%m;
}
void unlazy(int at, int l, int r){
    if(prop[at]){
        seg[at] = add(seg[at], multi(prop[at], r-l+1));
        if(l!=r){
            
        prop[at*2] = add(prop[at*2], prop[at]);
        prop[at*2+1] = add(prop[at*2+1], prop[at]);
        }
        prop[at]=0;
    }
}

int init(int at, int l, int r){
    if(l==r){
        return seg[at]=arr[l]%m;
    }
    int mid = (l+r)/2;
    return seg[at]=add(init(at*2, l, mid), init(at*2+1, mid+1, r));
}

int query(int at, int l, int r, int from, int to){
    unlazy(at, l, r);
    if(from>to)return 0;
    if(l==from&&r==to){
        return seg[at];
    }
    int mid=(l+r)/2;
    
    int temp= add(query(at*2, l, mid, from, min(to, mid)), query(at*2+1, mid+1, r, max(mid+1, from), to));
    seg[at] = add(seg[at*2], seg[at*2+1]);
    return temp;
}

int add(int at, int l, int r, int from, int to, int val){
    unlazy(at, l, r);
    if(from>to)return seg[at];
    if(l==from&&r==to){
        if(l==r)return seg[at]=add(seg[at],multi(val, r-l+1));
        prop[at*2]=add(prop[at*2], val);
        prop[at*2+1]=add(prop[at*2+1], val);
        return seg[at]=add(seg[at],multi(val, r-l+1));
    }
    int mid=(l+r)/2;
    return seg[at]=add(add(at*2, l, mid, from, min(to, mid), val), add(at*2+1, mid+1, r, max(mid+1, from), to, val));
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin>>m>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]%=m;
    }
    init(1,1,n);
    while(q--){
        int a;cin>>a;
        if(a==1){
            int b,c,d;cin>>b>>c>>d;
            add(1, 1, n, b,c,d%m);
        }   
        else{
            int b,c;cin>>b>>c;
            cout<<query(1,1,n,b,c)%m<<endl;
        }
    }
}