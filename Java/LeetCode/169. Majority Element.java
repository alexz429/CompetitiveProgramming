class Solution {
    public int majorityElement(int[] nums) {
        int cur = 0, count = 0;
        for(int i=0;i<nums.length;i++){
            if(count == 0){
                cur = nums[i];
                count = 1;
                continue;
            }
            if(cur == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return cur;
    }
}