#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PRECISION 1e-10
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int arr[2][4];
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    double a = (arr[0][0]-arr[0][2]!=0)?(double)(arr[0][1]-arr[0][3])/(arr[0][0]-arr[0][2]):(1e7);
    double b = (arr[1][0]-arr[1][2]!=0)?(double)(arr[1][1]-arr[1][3])/(arr[1][0]-arr[1][2]):(1e7);
    double c = (a==1e7)?arr[0][0]:(arr[0][1]-arr[0][0]*a);
    double d = (b==1e7)?arr[1][0]:(arr[1][1]-arr[1][0]*b);
    // cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
    cout<<setprecision(14);
    if(abs(a-b)<PRECISION){
        if(abs(c-d)<PRECISION){
            cout<<"coincident"<<endl;
        }
        else{
            cout<<"parallel"<<endl;
        }
    }
    else{
        if(a==1e7){
            cout<<arr[0][0]<<" "<<b*arr[0][0]+d<<endl;
        }
        else if(b==1e7){
            cout<<arr[1][0]<<" "<<a*arr[1][0]+c<<endl;
        }
        else{
            double ans = -(d-c)/(b-a);
            cout<<ans<<" "<<ans*a+c<<endl;
        }
    }
}