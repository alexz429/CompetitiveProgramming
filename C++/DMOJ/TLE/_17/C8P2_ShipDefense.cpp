#include <bits/stdc++.h>

using namespace std;

class defense{
    public:
    int s;
    int a;
    defense(int b, int c){
        s=b;
        a=c;
    }
    defense(){
        s=0;
        a=0;
    }
};
class shots{
    public:
    int start;
    int end;
    int damage;
    shots(){
        start=0;
        end=0;
        damage=0;
    }
};
bool startTime(shots a, shots b){
    return a.start<b.start;
}
bool endTime(shots a, shots b){
    return a.end<b.end;
}
int main(){
    int H, D, E;
    scanf("%d %d %d", &H, &D, &E);
    double health=H;
    defense* modes=new defense[D];
    for(int count=0;count<D;count++){
        int A, S;
        scanf("%d %d", &A, &S);
        modes[count].a=A;
        modes[count].s=S;
    }
    shots* starts=new shots[E];
    shots* ends=new shots[E];
    for(int count=0;count<E;count++){
        int start, dur, dmg;
        scanf("%d %d %d", &start, &dur, &dmg);
        starts[count].start=start;
        starts[count].end=start+dur;
        starts[count].damage=dmg;
        ends[count].start=start;
        ends[count].end=start+dur;
        ends[count].damage=dmg;
        
    }
    sort(&starts[0], &starts[E], startTime);
    sort(&ends[0], &ends[E], endTime);
    // for(int count=0;count<E;count++){
    //     printf("%d %d\n", starts[count].start, ends[count].end);
    // }
    int curTime=0;
    int curDmg=0;
    int startIndex=0;
    int endIndex=0;
    while(endIndex<E){
        
        double leastDmg=10000000;
        for(int count=0;count<D;count++){
            leastDmg=min(leastDmg, (double)max(0,curDmg-modes[count].s)*(1-((double)modes[count].a/100)));
        }
        // printf("%d %.2f\n",curTime, leastDmg);
    if(startIndex<E&&starts[startIndex].start<ends[endIndex].end){
        health-=leastDmg*(starts[startIndex].start-curTime);
        curTime=starts[startIndex].start;
        curDmg+=starts[startIndex].damage;
        startIndex++;
    }
    else{
        
        health-=leastDmg*(ends[endIndex].end-curTime);
        curTime=ends[endIndex].end;
        curDmg-=ends[endIndex].damage;
        endIndex++;
    }
    // printf("%f\n", health);
    }
    if(health<=0){
        printf("DO A BARREL ROLL!");
    }
    else{
        printf("%.2f", health);
    }

}