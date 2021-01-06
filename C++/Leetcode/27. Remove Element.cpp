//just check if element equals val, then erase. 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
                i--;//subtract 1 from pointer to not skip over element.
            }
        }
        return nums.size();
    }
};