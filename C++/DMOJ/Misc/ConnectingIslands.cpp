#include <bits/stdc++.h>

using namespace std;

int **grid;
int curPoint = 1;
int row, col;
int*** shortest;
void recurse(int x, int y)
{
    if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] != -1)
    {
        return;
    }
    grid[x][y] = curPoint;
    recurse(x - 1, y);
    recurse(x + 1, y);
    recurse(x, y - 1);
    recurse(x, y + 1);
}
void init(int x, int y){
    for(int count=0;count<row;count++){
        for(int count2=0;count2<col;count2++){
            int temp=grid[count][count2];
            if(temp!=0){
                shortest[x][y][temp]=min(shortest[x][y][temp], abs(count-x)+abs(count2-y)-1);
            }
        }
    }
}
int main()
{
    cin>>row>>col;
    grid = new int *[row];
    int huh=4;
    shortest=new int**[row];
    for(int count=0;count<row;count++){
        shortest[count]=new int*[col];
        for(int count2=0;count2<col;count2++){

            shortest[count][count2]=new int[4];
            fill(&shortest[count][count2][0], &shortest[count][count2][4], 5000);
        }
    }
    for (int count = 0; count < row; count++)
    {
        string next;
        cin>>next;
        grid[count] = new int[col];
        for (int count2 = 0; count2 < col; count2++)
        {
            if (next.at(count2) == '.')
            {
                grid[count][count2] = 0;
            }
            else
            {
                grid[count][count2] = -1;
            }
            // printf("%d", grid[count][count2]);
        }
    }
    // printf("\n");
    for (int count = 0; count < row; count++)
    {
        for (int count2 = 0; count2 < col; count2++)
        {

            if (grid[count][count2] == -1)
            {
                recurse(count, count2);
                curPoint++;
            }
            // printf("%d", grid[count][count2]);
        }
        // printf("\n");
    }
    int best[7];
    fill(&best[0], &best[7], 5000);
    for(int count=0;count<row;count++){
        for(int count2=0;count2<col;count2++){
            init(count,count2);
            best[0]=min(best[0], shortest[count][count2][2]+shortest[count][count2][1]+shortest[count][count2][3]+1);
            best[2]=min(best[2], 1+shortest[count][count2][1]+shortest[count][count2][2]);
            best[3]=min(best[3], 1+shortest[count][count2][1]+shortest[count][count2][3]);
            best[6]=min(best[6], 1+shortest[count][count2][3]+shortest[count][count2][2]);
        }
    }
    printf("%d", min(best[0], best[2]+best[3]+best[6]-max(best[2], max(best[3],best[6]))));
    
    
}
