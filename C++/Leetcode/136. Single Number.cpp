//xoring a number twice cancels out the number. 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out = 0;
        for(int i=0;i<nums.size();i++){
            out ^= nums[i];
        }
        return out;
    }
};