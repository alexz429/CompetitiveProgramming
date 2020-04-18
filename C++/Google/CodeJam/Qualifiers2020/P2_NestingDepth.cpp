#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": ";
        string in;
        cin>>in;
        int cur = 0;
        for(int j=0;j<in.length();j++){
            int comp = in[j]-'0';
            while(cur<comp){
                cur++;
                cout<<"(";
            }
            while(cur>comp){
                cur--;
                cout<<")";
            }
            cout<<in[j];
        }
        while(cur>0){
            cout<<")";
            cur--;
        }
        cout<<endl;
    
    }
    
}  