#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<pair<int,int>,pair<int,int>> limits;

string attempt(int a, int b){
    cout<<a<<" "<<b<<endl;
    string next;cin>>next;
    return next;
}

void solve(int A,int B){
    limits = {{-1000000000,1000000000},{-1000000000,1000000000}};
    for(int i=0;i<4;i++){
        bool flag = false;
        for(int j=0;j<4;j++){
            int temp = (-750000000+i*500000000);
            int temp2=(-750000000+j*500000000);
            string next = attempt(temp, temp2);
            if(next.compare("CENTER")==0){
                return;
            }
            if(next.compare("HIT")==0){
                cout<<"OK"<<endl;
                limits ={{max(temp-B/2-1,-1000000000), min(temp+B/2+1,1000000000)},{max(temp2-B/2-1,-1000000000), min(temp2+B/2+1,1000000000)}};
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    while(true){
        for(int i=1;i<4;i+=2){
            for(int j=1;j<4;j+=2){
                cout<<limits.first.first<<" "<<limits.first.second<<" "<<limits.second.first<<" "<<limits.second.second<<endl;
                int diffX = (limits.first.second-limits.first.first+1)/4*i+limits.first.first;
                int diffY = (limits.second.second-limits.second.first+1)/4*j+limits.second.first; 
                string next = attempt(diffX,diffY);
                if(next.compare("CENTER")==0)return;
                if(next.compare("HIT")==0){
                     limits ={{max(diffX-B/2-1,limits.first.first), min(diffX+B/2+1,limits.first.second)},{max(diffY-B/2-1,limits.second.first), min(diffY+B/2+1,limits.second.second)}};
                }
            }
        }
    }

}

int main(){
    int T,A,B;
    cin>>T>>A>>B;
    for(int p=0;p<T;p++){
        solve(A,B);
    }
}