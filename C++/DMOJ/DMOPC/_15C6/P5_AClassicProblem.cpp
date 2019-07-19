#include <bits/stdc++.h>
using namespace std;
#define ll long long
deque<int> big;
deque<int> small;
int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int* vals=new int[n];
    int size=0;
    ll tally=0;
    for(int count=0;count<n;count++){
        scanf("%d", &vals[count]);

        while(!big.empty()&&big.back()<vals[count])big.pop_back();
        big.push_back(vals[count]);
        while(!small.empty()&&small.back()>vals[count])small.pop_back();
        small.push_back(vals[count]);

        size++;
        while(big.front()-small.front()>k&&size>0){
            change=true;
            // printf("%d %d\n", size, count);
            
            if(big.front()==vals[count-size+1]){
                big.pop_front();
            }
            if(small.front()==vals[count-size+1]){
                small.pop_front();
            }
            size--;
        }
tally+=size;
        
       
    }
    printf("%lld\n", tally);
    
}