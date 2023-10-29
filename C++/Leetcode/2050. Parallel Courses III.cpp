class Solution {
public:

    int recurse(int at, vector<int>& dp, const vector<vector<int>>& graph, const vector<int>& time){
        if(dp[at] != -1) return dp[at];
        int worst = 0;
        for(auto next: graph[at]){
            worst = max(worst, recurse(next, dp, graph, time));
        }
        return dp[at] = worst + time[at];
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
       vector<int> dp;
       vector<vector<int>> graph;
       for(int i=0;i<n;i++){
           dp.push_back(-1);
           graph.push_back(vector<int>());
       } 
       for(auto next: relations){
           graph[next[1] - 1].push_back(next[0] - 1);
       }
       int worst = 0;
       for(int i=0;i<n;i++){
           worst = max(worst, recurse(i, dp, graph, time));
       }
        return worst;
    }
};