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
        if(l==r)return;
        prop[at*2] = add(prop[at*2], prop[at]);
        prop[at*2+1] = add(prop[at*2+1], prop[at]);
        prop[at]=0;
    }
}

int init(int at, int l, int r){
    if(l==r){
        return seg[at]=arr[l]%m;
        // cout<<at<<" "<<seg[at]<<endl;
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
    return add(query(at*2, l, mid, from, min(to, mid)), query(at*2+1, mid+1, r, max(mid+1, from), to));
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
    int og = 0;
    // for(int i=1;i<=n;i++){
    //     cin>>arr[i];
    //     arr[i]%=m;
    //     if(i>=106&&i<=397){
    //         og=(og+arr[i])%2;
    //     }
    // }
    if(n!=5)cout<<og<<" "<<n<<endl;
    init(1,1,n);
    while(q--){
        int a;cin>>a;
        if(a==1){
            int b,c,d;cin>>b>>c>>d;
            
            if(d%2==1){
                for(int i=b;i<=c;i++){
                    arr[i]^=1;
                }
            }
            if(n!=5){
                if(c>=106&&b<=397){
                    int out = 0;
            for(int j=106;j<=397;j++){
                out+=arr[j];
            }
            out%=2;

            cout<<out<<" "<<query(1,1,n,106,397)<<endl;
            if(out!=query(1,1,n,106,397)){
                cout<<b<<" "<<c<<" "<<d<<"o"<<endl;
            }
                }
                //     int gap = min(c, 397)-max(b, 106)+1;
                //     cout<<((d%2)*gap)%2<<endl;
                // }
                
            }
            add(1, 1, n, b,c,d%m);
        }   
        else{
            int b,c;cin>>b>>c;
            // if(n!=5)cout<<" "<<b<<" "<<c<<" "<<" ";
            if(n!=5){
                
            int out = 0;
            for(int i=b;i<=c;i++){
                out+=arr[i];
            }
            out%=2;
            int comp = query(1,1,n,b,c);
            if(comp!=out){
                cout<<comp<<" "<<b<<" "<<c<<endl;
            }
            }
            else{
                
            cout<<query(1,1,n,b,c)%m<<endl;
            }
        }
    }
}