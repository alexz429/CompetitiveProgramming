#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int N, K, pos[202][MM], cur, pre, now = 1, q[MM], f, r; ll dp[2][MM], psa[MM], ans = -1;
deque<pair<int,int>> test;
//dp[k][i] = dp[k-1][x] + (psa[n]-psa[i])*(psa[i]-psa[x]);
bool comp(int first, int second, int index){
    return dp[pre][first] + (psa[N]-psa[index])*(psa[index]-psa[first])<dp[pre][second] + (psa[N]-psa[index])*(psa[index]-psa[second]);
}
int main(){
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++) { scanf("%lld", &psa[i]); psa[i] += psa[i-1]; 
    // printf("%d ", psa[i]);
    }
    for(int k=1; k<=K; k++){
        // printf("%d \n", k);
        memset(dp[now], -1, sizeof(dp[now]));
        for(int count=k-1;count<N;count++){ // the overall 1d1d thing
            // printf("%d ", count);
            while(test.size()>0&&comp(test.back().first,count,test.back().second)){
                test.pop_back();
            }
            if(test.size()==0){
                test.emplace_back(count,1);
                continue;
            }
            int left=max(count+1,test.back().second+1);
            int right=N;
            // printf("%d %d %d\n", left, right, count);
            while(left!=right){
                int mid=(left+right)/2;
                if(comp(test.back().first,count,mid)){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
                // printf("%d %d\n", left, right);
            }
            if(right==N)continue;
            test.emplace_back(count,right);
        }

        int cur=test.front().first;
        for(int i=k-1; i<=N; i++){// the filling of actual values: had to set k-1 or else everything breaks (even though this should just be a TLE thing)
            while(test.size()>0&&i>=test.front().second){
                cur=test.front().first;
                test.pop_front();
            }
            // printf("%d %lld A %lld ", i,  psa[i], psa[cur]);
            dp[now][i]=dp[pre][cur] + (psa[N]-psa[i])*(psa[i]-psa[cur]);
            
            pos[k][i]= cur;
           
            // printf("%lld %d - ", dp[now][i], cur);
        }
        // printf("\n");
        pre^=1; now^=1;
    }
    for(int i=K; i<=N; i++)
        if(dp[pre][i] > ans){ ans = dp[pre][i]; cur = i; }
    printf("%lld\n", ans);
    for(int i=K; i>0; i--){
        printf("%d ", cur); cur = pos[i][cur];
    }
}