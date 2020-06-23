#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[15][4];
double s;
double dp[32768][15];
pair<double,double> pos[32768][15];

double solve(int idx, double pX, double pY, double timePassed){
    double sX = arr[idx][0], sY = arr[idx][1], vX = arr[idx][2], vY = arr[idx][3];
    sX += vX*timePassed;
    sY += vY*timePassed;
    double dX = sX-pX, dY = sY-pY;
    double a = (s*s-pow(vX,2)-pow(vY,2)), b = (-2*dX*vX-2*dY*vY), c = (-pow(dX,2)-pow(dY,2));
    double left = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
    double right = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
    // cout<<a<<" "<<b<<" "<<c<<" "<<left<<" "<<right<<endl;
    return max(left,right);
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    fill(&dp[0][0], &dp[32767][15], 1e15+1);
    for(int i=1;i<pow(2,n);i++){
        int bit = 1;
        for(int j=0;j<n;j++, bit<<=1){
            if((bit&i)==0)continue;
            int ptr = i^bit;
            if(ptr==0){
                dp[i][j] = solve(j,0,0,0);
                pos[i][j] = {arr[j][0]+arr[j][2]*dp[i][j], arr[j][1]+arr[j][3]*dp[i][j]};
            }
            else{
            int bit2 = 1;
            for(int k=0;k<n;k++,bit2<<=1){
                if(bit2&ptr==0)continue;
                double temp = solve(j, pos[ptr][k].first, pos[ptr][k].second, dp[ptr][k]) + dp[ptr][k];
                if(dp[i][j]>temp){
                    dp[i][j] = temp;
                    pos[i][j] = {arr[j][0]+arr[j][2]*dp[i][j], arr[j][1]+arr[j][3]*dp[i][j]};
                }
            }
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<"\n";
    }
    double best = 1e15+1;
    for(int i=0;i<n;i++){
        best = min(best, dp[(int)pow(2,n)-1][i]);
    }
    cout<<fixed<<setprecision(9)<<best<<endl;
}