#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    string a,b;
    getline(cin,a);
    getline(cin, a);
    getline(cin, b);
    int t = 0;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
        if(a[i]=='0'&&b[i]=='0'){
            t++;
        }
    }
    cout<<t<<endl;
}