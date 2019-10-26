#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M;
vector<pair<int,int>> dir[2550];
ll hashes[50][50];
int length[50];
// let node[x][i] be the representation of segment i of code x
// x[i] -> y[j] implies a word can fit to bring the current position to y[j]
// then djikstra or something I guess
// since x,i<=50, combine node[x][i] into node[x*50+i] for easier stuff
ll cut(int index, ll l, ll r){
return hashes[index][r]&(1<<(r-l+1)-1);
}
void preprocess(int at){
//unpack to x and i
int x=at/51;
int i=at%51;
cout<<"HI "<<x<<" "<<i<<endl;
int rem=length[x]-1-i;
ll leadHash=cut(x,i,length[x]-1);
for(int count=0;count<N;count++){
    if(length[count]<=rem){
        if(cut(x,i,i+length[count])==hashes[count][length[count]-1]){
            dir[at].emplace_back(x*51+i+length[count],length[count]);
            cout<<"Link from "<<x<<" "<<i<<"to "<<x<<" "<<i+length[count]<<endl;
            if(i+length[count]!=length[x]-1){
                cout<<"CALL"<<endl;
                preprocess(x*51+i+length[count]);
            }
        }
    }
    else{
        ll compHash=hashes[count][rem];
        if(compHash==leadHash){
            cout<<x<<" "<<i<<" MATCHES "<<count<<rem<<endl;
            ll newHash=cut(count,rem,length[count]-1);
            
            int newRem=length[count]-rem;
            for(int count2=0;count2<N;count2++){
                if(newHash==hashes[count2][newRem-1]){
                    dir[at].emplace_back(count2*51+newRem-1,length[count]);
                    cout<<"JUMP from "<<x<<" "<<i<<"to "<<count2<<" "<<newRem<<"USING "<<count<<endl;
                    if(i+length[count]!=length[x]-1){
                        cout<<"POP"<<endl;
                        preprocess(count2*51+newRem-1);
                    }
                }
            }
        }
    }
}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int count=0;count<N;count++){
        string next;
        cin>>next;
        ll cur=0;
        length[count]=next.length();
        for(int i=0;i<next.length();i++){
            cur*=2;
            if(next[i]=='1'){
                cur+1;
            }
        }
    }
    for(int count=0;count<N;count++){
        preprocess(count*51);
    }


}