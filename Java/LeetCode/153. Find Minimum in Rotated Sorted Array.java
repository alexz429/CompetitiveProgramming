class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l == nums.length) {
            return nums[0];
        }
        return nums[l];

    }
}