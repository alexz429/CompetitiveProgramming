#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i=0;
string in;
bool monkey(){
    
    // cout<<i<<" ";
   bool out = true;
   if(in[i] == 'A'){
       i++;
   }
   else if(in[i] =='B'){
       i++;
       
       if(monkey()&&in[i] == 'S'){
           i++;
       }
       else{
           return false;
       }
   }
   else{
       return false;
   }

    if(in[i] == 'N'){
        i++;
        return monkey();
    }
    return true;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>in;
    while(in.compare("X")!=0){
        i=0;
        if(monkey()&&i==in.length()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
    }

        cin>>in;
    }
}