#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int tally=0;
    for(int i=0;i<(1<<n);i++){
        //analyzing which bits are set
        int sum =0;
        int temp = i;//creates a temporary value to store i, because temp will be changed
        for(int j=0;j<n;j++){
            if(temp&1==1){ // checks if the first bit of temp is set by using the AND bitwise operator    
                sum+=coins[j];//adds the coins into a sum
            }
            temp>>=1;//shifts temp to the right by 1 every time
        }
        if(sum == m){
           tally++;
        }
    }
    cout<<tally<<endl;
}