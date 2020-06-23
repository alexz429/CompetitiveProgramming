#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;
    // cout<<(-2%2)<<endl;
    cin>>n;
    int arr[n];
    int tot = 0;
    int sum = 0;
    pair<int,int> lim = {0, 1000002};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i!=0){
            tot = arr[i] - tot;
            if(i%2==1){
                lim.second = min(lim.second, tot);
            }
            else{
                lim.first = max(lim.first, -1*tot);
            }
        }
        sum+=arr[i];
    }
    // cout<<lim.first<<" "<<lim.second<<endl;
    if(lim.first>lim.second){
        cout<<"NO"<<"\n";
        return 0;
    }
    if(n%2==0){
        if(tot==arr[0]){
            arr[0] = lim.first;
            cout<<"YES"<<"\n";  
            cout<<sum/2<<"\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<arr[i];j++){
                    int temp = (i+1)%n;
                    cout<<i<<" "<<temp<<"\n";
                }
                arr[(i+1)%n]-=arr[i];
            }
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    else{
        if(arr[0]>=tot&&(arr[0]-tot)%2==0&&(arr[0]-tot)/2>=lim.first&&(arr[0]-tot)/2<=lim.second){
            cout<<"YES"<<"\n";  
            cout<<sum/2<<"\n";
            arr[0] = (arr[0]-tot)/2;
            for(int i=0;i<n;i++){
                for(int j=0;j<arr[i];j++){
                    int temp = (i+1)%n;
                    cout<<i<<" "<<temp<<"\n";
                }
                arr[(i+1)%n] -= arr[i];
            }
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}