class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int val = 0;
        int best = 0;
        while(true){
            if(val < target){
                if(r >= nums.size()) break;
                val+=nums[r++];
            }
            else{
                if(best==0||r-l<best){
                    best = r-l;
                }
                val-=nums[l++];
            }
        }
        return best;
    }
};