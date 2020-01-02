#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int equation[6];
int first[5];

double interval(double a, double b, double increment){
    // cout<<a<<" "<<b<<" "<<increment<<endl;
    double prev = 0;
    for(double i=a; i<=b+increment;i+=increment){
        double cal = 0;
        for(int j=0;j<6;j++){
            cal+= equation[j]*pow(i,j);
        }
        // cout<<i<<" "<<cal<<endl;
        if(cal == 0){
            return i;
        }
        if(prev!=0&&((prev<0&&cal>0)||(prev>0&&cal<0))){
            if(increment<0.00000001) return i;
            return interval(i-increment, i, increment*0.1);
        }
        prev = cal;
    }
    return 123456789;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n1,n2;
    
    cin>>n1;
    for(int i=n1;i>=0;i--){
        cin>>equation[i];
    }
    cin>>n2;
    for(int i=n2;i>=0;i--){
        int next;
        cin>>next;
        equation[i] -= next;
        // cout<<equation[i]<<" ";
    }
    // cout<<endl;
    int a,b;
    cin>>a>>b;
    for(int i=4;i>=0;i--){
        first[i] = equation[i+1]*(i+1);
        // cout<<first[i]<<" ";
    }
    cout<<fixed<<setprecision(8)<<interval(a,b,1);
    

}