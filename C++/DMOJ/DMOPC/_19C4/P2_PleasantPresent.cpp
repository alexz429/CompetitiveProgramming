#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int verti,hori;
int tally;
void first(int x, int y, int a, int b, int xDis, int yDis){
    int c,d;
    if(xDis!=0){
        c = a + (xDis>0?1:-1);
    }
    else{
        c = 10000;
    }
    if(yDis!=0){
        d = b + (yDis>0?1:-1);
    }
    else{
        d = 10000;
    }
    hori = abs(y-b)+abs(x-c);
    verti = abs(y-d)+abs(x-a);
    
    // cout<<hori<<" "<<verti<<endl;
    if(x==a&&(y-b)*yDis<0){
        verti+=2;
    }
    if(y==b&&(x-a)*xDis<0){
        hori+=2;
    }
}
void second(int a, int b, int xDis, int yDis){
    int small = min(abs(xDis), abs(yDis));
    tally+=small*3*2;
    tally-=2;
    // cout<<tally<<endl;
    if(abs(yDis)>abs(xDis)){
        verti-=2;
    }
    else if(abs(xDis)>abs(yDis)){
        hori-=2;
    }
    int diff = abs(abs(xDis)-abs(yDis));
    tally+=diff*5;
    tally+=min(verti,hori);

}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    if(a==c&&b==d){
        cout<<0<<endl;
        return 0;
    }
    int e,f,g,h;
    cin>>e>>f>>g>>h;
    int x,y;
    if(e==a&&f==b){
        x=g;y=h;
    }
    else{
        x=e;y=f;
    }
    int xDis = (c-a);
    int yDis = (d-b);
    first(x,y,a,b,xDis,yDis);
    // cout<<tally<<endl;
    second(a,b,xDis,yDis);
    cout<<tally<<endl;
}