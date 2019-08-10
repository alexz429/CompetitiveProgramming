#include <bits/stdc++.h>
//NOT DONE
using namespace std;
class junction{
    public:
    bool start;
    int rem;
    int B;
    int P;
    int index;
    long length=LONG_MAX;
};
class compare{
    public:
    bool operator()(junction a, junction b){
        return a.length<b.length;
    }
};

int djik[300];
int backTrack[300];
junction properties[300];
vector<pair<int,int>> direct[300];
long shortest(junction a, pair<int,int> path){
    junction b=properties[path.first];
    // printf("%d %d %d | %d %d %d\n", a.rem,a.B,a.P, b.rem,b.B,b.P);
    long startTime=a.length;
     int phaseA=(startTime-a.rem-(a.start?a.B:0)+a.P+a.B)%(a.P+a.B);
     int phaseB=(startTime-b.rem-(b.start?b.B:0)+b.P+b.B)%(b.P+b.B);
    
    bool left=(phaseA>=a.P)?true:false;
    bool right=(phaseB>=b.P)?true:false;
    
    // printf("%d %d %d %d %d\n", startTime, phaseA, phaseB, left, right);
    if(left==right){
        return startTime+path.second;
    }
    for(int count=0;count<3;count++){
        
        int nextLeft=(phaseA>=a.P)?(a.P+a.B-phaseA):(a.P-phaseA);
        int nextRight=(phaseB>=b.P)?(b.P+b.B-phaseB):(b.P-phaseB);
        // printf("%d %d\n", nextLeft,nextRight);
        startTime+=min(nextLeft,nextRight);
           phaseA=(startTime-a.rem-(a.start?a.B:0)+a.P+a.B)%(a.P+a.B);
    phaseB=(startTime-b.rem-(b.start?b.B:0)+b.P+b.B)%(b.P+b.B);
    
     left=(phaseA>=a.P)?true:false;
     right=(phaseB>=b.P)?true:false;
     
    // printf("%d %d %d %d %d\n", startTime, phaseA, phaseB, left, right);
    if(left==right){
        return startTime+path.second;
    }
    }

    return -1;
    

}
void track(int from, int start){
    if(from==start){
        return;
    }
    track(backTrack[from], start);
    printf("%d ", backTrack[from]+1);
}
int main(){
    // junction test;
    // test.start=false;
    // test.B=16;
    // test.P=99;
    // test.rem=2;
    // test.length=0;
    // properties[0].start=true;
    // properties[0].B=32;
    // properties[0].P=13;
    // properties[0].rem=6;
    // pair<int,int> lol(0,4);
    // printf("%d", shortest(test,lol));
    int start,end;
    scanf("%d %d", &start,&end);
    start--;
    end--;
    int nodes, edges;
    scanf("%d %d%*c",&nodes, &edges);
    for(int count=0;count<nodes;count++){
        char val;
        int rem,B,P;
        scanf("%c %d %d %d%*c", &val,&rem,&B,&P);
        // printf("%c\n", val);
        properties[count].start=(val=='B')?false:true;
        properties[count].rem=rem;
        properties[count].B=B;
        properties[count].P=P;
        properties[count].index=count;

    }
    for(int count=0;count<edges;count++){
        int from,to,weight;
        
        scanf("%d %d %d", &from,&to, &weight);
        direct[--from].emplace_back(--to,weight);
        direct[to].emplace_back(from,weight);
    }
    unordered_multiset<int> visited;
    properties[start].length=0;
    int index=start;
    while(visited.size()<nodes){
        visited.insert(index);
        // printf("%d\n", index);
        junction nextNode=properties[index];
        for(pair<int,int> next:direct[nextNode.index]){
            // printf("running %d %d\n", nextNode.index, next.first);
            int comp=shortest(nextNode,next);
            if(comp!=-1&&comp<properties[next.first].length){
                properties[next.first].length=comp;
                backTrack[next.first]=nextNode.index;
            }
        }
        int small=100000000;
        for(int count=0;count<nodes;count++){
            if(visited.find(count)!=visited.end())continue;
            // printf("test %d\n", count);
            if(small>properties[count].length){
                
                small=properties[count].length;
                index=count;
            }
        }
    }
    if(properties[end].length==1e18){
        printf("0\n");
        return 0;
    }
    printf("%lld\n", properties[end].length);
    track(end,start);
    printf("%d\n", end+1);
}