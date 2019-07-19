#include <bits/stdc++.h>
using namespace std;
class point{
    public:
    int x;
    int y;
    double angle;
    point(){
        x=0;
        y=0;
    }
    point(int a, int b){
        x=a;
        y=b;
    }
};
bool comparePoints(point a, point b){
    if(a.angle==b.angle){
        return a.x<b.x;
    }
    return a.angle<b.angle;
}
double getAngle(point a,point b, point c){//where a is the angle needed, IN RADIANS
if(a.x==b.x&&a.y==b.y)return -1;
if(b.y==a.y)return 0;
    double l1=sqrt(pow(abs(a.x-b.x),2)+pow(abs(a.y-b.y),2));
    double l2=sqrt(pow(abs(c.x-b.x),2)+pow(abs(c.y-b.y),2));
    double l3=sqrt(pow(abs(a.x-c.x),2)+pow(abs(a.y-c.y),2));
    // cout<<l1<<" "<<l2<<" "<<l3<<endl;
    
    return acos((pow(l1,2)+ pow(l3,2)-pow(l2,2))/(2*l1*l3));
}
int crossProd(point a, point b, point c){// <0 is left turn, >0 is right turn
// cout<<"active\n";
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
point* input;
int main(){
    point a(1,1);
    point b(1,1);
    point c(0,0);
    // cout<<getAngle(a,b,c);
    int max;
    scanf("%d", &max);
    input=new point[max];
    point lowest;
    lowest.y=2000;
    for(int count=0;count<max;count++){
        int x,y;
        scanf("%d %d", &x, &y);
        input[count].x=x;
        input[count].y=y;
        if(y<lowest.y||(y==lowest.y&&x<lowest.x)){
            lowest=input[count];
        }

    }
    // printf("%d %d", lowest.x,lowest.y);
    point other;
    other.y=lowest.y;
    other.x=2000;
    
    for(int count=0;count<max;count++){
        input[count].angle=getAngle(lowest, input[count], other);
    }
    sort(&input[0], &input[max], comparePoints);
    // for(int count=0;count<max;count++){
    //     cout<<input[count].angle<<endl;
    // }
    
    stack<point> items;
    items.push(input[0]);
    items.push(input[1]);
    for(int count=2;count<max;count++){
        point prev=items.top();
        // cout<<prev.x<<" "<<prev.y<<endl;
        items.pop();
        while(items.size()>1&&crossProd(items.top(), prev, input[count])<=0){
            
            // cout<<"kill"<< items.top().x<<" "<<items.top().y<<" "<<prev.x<<" "<<prev.y<<" "<<input[count].x<<" "<<input[count].y<<endl;
            prev=items.top();
            items.pop();
        }
        items.push(prev);
        items.push(input[count]);
    }
    double add=0;
    bool first=true;
    items.push(input[0]);
    point prev(-1,-1);
    while(!items.empty()){
        point next=items.top();
        // cout<<next.x<<" "<<next.y<<endl;
        items.pop();
        if(prev.x!=-1){
            add+=(prev.x*next.y-prev.y*next.x);
        }
        prev=next;
    }
        cout<<((int)abs(add/2)/50)<<endl;
    }