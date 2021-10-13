class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        int[] out = new int[2];
        if (nums.length == 0) {
            out[0] = out[1] = -1;
            return out;
        }
        while (l < r) {
            int mid = (l + r - 1) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] != target) {
            out[0] = out[1] = -1;
            return out;
        }
        out[0] = l;
        l = 0;
        r = nums.length - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        out[1] = l;
        return out;
    }
}