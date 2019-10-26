#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x,y, x2,y2, d;
    cin>>x>>y>>x2>>y2>>d;
    int low = abs(x-x2) + abs(y-y2);
    
    if((low==1&&d!=1)||low>d||(d-low)%2!=0){
        printf("impossible\n");
        return 0;
    }
    int change=0;
    if(abs(x-x2)==1&&abs(y-y2)==1){
        if(abs(d-low)==2){
            
        printf("impossible\n");
        return 0;
        }
        // else{
        //     change=1;
        // }
        change = 1;
    }
    int vertMod = ((y2-y)>0)?1:-1;
    int horiMod = ((x2-x)>0)?1:-1;
    int diff = (d-low)/2;
    diff-=change;
    diff = max(0,diff);
    printf("%d\n", diff*2);
    for(int i=0;i<diff;i++){
        printf("%d %d\n", x+horiMod,y-(i*vertMod));
        printf("%d %d\n", x-(i*horiMod),y+vertMod);
    }

}