#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	// TODO Auto-generated method stub
    cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i]; 
  }
  sort(&arr[0], &arr[n]);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<endl; 
  }
}


