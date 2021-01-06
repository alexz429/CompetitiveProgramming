//binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};