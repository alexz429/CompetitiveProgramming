#include <bits/stdc++.h>
using namespace std;
bool visit[10][10];

pair<int,int> start(-1,-1);
pair<int,int> endP(-1,-1);
int main(){
    for(int count3=0;count3<10;count3++){
for(int count=0;count<10;count++){
        for(int count2=0;count2<10;count2++){
            char next;
            scanf("%c", &next);
            if(next=='#'){
                visit[count][count2]=true;
            }
            else if(next=='X'){
                if(start.first==-1){
                    start.first=count;
                    start.second=count2;
                }
                else{
                    endP.first=count;
                    endP.second=count2;
                }
            }
        }
        scanf("%*c");
    }
    queue<pair<int,int>> queue;
    queue.push(start);
    int steps=0;
    bool done=false;
    while(!queue.empty()){
        int max=queue.size();
        for(int count=0;count<max;count++){
        pair<int,int> next=queue.front();
        queue.pop();
        if(next.first<0||next.first>9||next.second<0||next.second>9){
            continue;
        }
        if(visit[next.first][next.second]){
            continue;
        }
        visit[next.first][next.second]=true;
        if(next.first==endP.first&&next.second==endP.second){
            printf("%d\n", steps);
            done=true;
            break;
        }
        queue.emplace(next.first-1,next.second);
        queue.emplace(next.first+1,next.second);
        queue.emplace(next.first,next.second+1);
        queue.emplace(next.first,next.second-1);
        queue.emplace(next.first-1,next.second-1);
        queue.emplace(next.first+1,next.second+1);
        queue.emplace(next.first-1,next.second+1);
        queue.emplace(next.first+1,next.second-1);
        }
        steps++;
        if(done){
            break;
        }
    }
    scanf("%*[^\n]\n");
    start=pair<int,int>(-1,-1);
    endP=pair<int,int>(-1,-1);
    for(int count=0;count<10;count++){
        fill(&visit[count][0], &visit[count][10], false);
    }
    }
    
}