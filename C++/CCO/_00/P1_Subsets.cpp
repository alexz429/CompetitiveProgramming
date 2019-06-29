#include <bits/stdc++.h>

using namespace std;
bool enable[26];
vector<int> has[26];
bool output[26][26];
bool visited[26];
int same[26];
int tally = 1;

bool checkCycle(int at, int origin)
{
    // printf("AT: %d", at);

    if (visited[at])
        return at==origin;
    visited[at] = true;
    bool found = false;
    for (int next : has[at])
    {
        if (checkCycle(next, origin))
        {
            same[at] = tally;
            found = true;
        }
    }
    return found;
}
void recurse(int at)
{   
    if(visited[at])return;
    visited[at]=true;
    
    // printf("%d\n", at);
    for (int next : has[at])
    {
        // printf("GOES TO %d\n", next);
        if (same[next]!=0&&same[next] == same[at])
            continue;
        recurse(next);
        for(int count=0;count<26;count++){
            if(output[next][count]){
                output[at][count]=true;
            }
        }
    }
}
int main()
{
    int max;
    fill(&enable[0], &enable[26], false);
    fill(&same[0], &same[26], 0);
    for(int count=0;count<26;count++){
        fill(&output[count][0],&output[count][26], false);
    }
    cin>>max;
    string useless;
    getline(cin,useless);
    for (int count = 0; count < max; count++)
    {
        string nextLine;
        getline(cin,nextLine);
        char from, to;
        from=nextLine.at(0);
        to=nextLine.at(11);
        // printf("%c %c", from,to);
        int f = from - 'A';
        int t=to-'A';
        // printf("%d %d\n", f,t);
        if (t <= 26)
        {

            has[f].push_back(t);
            // printf("%d", t);
            enable[t] = true;
        }
        else
        {
            output[f][to-'a']=true;
        }
        enable[f] = true;
    }
    for (int count = 0; count < 26; count++)
    {
        if (enable[count])
        {
            fill(&visited[0], &visited[26], false);
            if (same[count]==0&&checkCycle(count, count))
                tally++;
        }
    }
    // for(int count=0;count<26;count++){
    //     printf("%d %d\n", count, same[count]);
    // }
    fill(&visited[0], &visited[26], false);
    for(int count=0;count<26;count++){
        if(enable[count])recurse(count);
    }
    for(int count=0;count<26;count++){
        if(same[count]!=0){
            for(int i=0;i<26;i++){
                if(same[count]==same[i]){
                    for(int x=0;x<26;x++){
                        if(output[count][x]){
                            output[i][x]=true;
                        }
                    }
                }
            }
        }
    }
    for (int count = 0; count < 26; count++)
    {
        if (enable[count])
        {
            printf("%c = {", (char)(count+'A'));
            bool first=true;
            for(int i=0;i<26;i++){
                
                if(output[count][i]){
                    if(!first)printf(",");
                first=false;
                    printf("%c", (char)(i+'a'));
                }
            }
            printf("}\n");
        }
    }
}