#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int lol=0;lol<n;lol++){
        string word;
        cin>>word;
        int even = 0;
        bool flag = true;
        for(int i=0;i<word.length();i++){
            if(word[i]=='('){
                even++;
            }
            else if(word[i]==')'){
                even--;
            }
            else if(word[i]-'0'<10&&word[i]-'0'>=0){

            }
            else{
                flag = false;
                break;
            }
            if(even<0){
                flag = false;
                break;
            }
            
        }
        if(!flag||even!=0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
}