class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> output;
        map<int, vector<int>> proc;
        for(int i=0;i<groupSizes.size();i++){
            int next = groupSizes[i];
            if(!proc.count(next)){
                proc[next] = vector<int>();
            }
            proc[next].push_back(i);
            if(proc[next].size() == next){
                output.push_back(proc[next]);
                proc[next].clear();
            }
        }
        return output;
    }
};