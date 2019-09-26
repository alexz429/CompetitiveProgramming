#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int temp=0;
    for(int count=0;count<=b;count++){
        if(temp%b==c){
            cout<<"YES"<<endl;
            return 0;
        }
        temp+=a;
    }
    cout<<"NO"<<endl;
    return 0;
}