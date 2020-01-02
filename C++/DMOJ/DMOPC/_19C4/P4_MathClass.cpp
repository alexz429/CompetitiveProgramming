#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    
    if(n!=1){
        cout<<-1<<endl;
    }
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c&&b==d){
        cout<<0<<endl;
        return 0;
    }
    double x,y;
    cin>>x>>y;
    double left = (double)sqrt(pow(abs(a-x),2)+pow(abs(b-y),2));
    double right = (double)sqrt(pow(abs(c-x),2)+pow(abs(d-y),2));
    // cout<<left<<" "<<right<<endl;
    if(abs(sqrt(pow(abs(a-x),2)+pow(abs(b-y),2))-sqrt(pow(abs(c-x),2)+pow(abs(d-y),2)))<0.00000001){
        cout<<1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}