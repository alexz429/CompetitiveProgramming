class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sums = 0;
        int best = -2147483647;
        for(int next: nums){
            sums += next;
            sums = max(next, sums); //if past sums is worse than just taking the cur val, take cur val.
            best = max(best, sums);
        }
        return best;
    }
};