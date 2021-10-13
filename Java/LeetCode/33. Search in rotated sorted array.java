class Solution {
    public int search(int[] nums, int target) {

        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int k = nums.length - l;
        // System.out.println(k);
        l = 0;
        r = nums.length - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            System.out.print(mid + " ");
            int adjust = mid;
            if (mid < k) {
                adjust += nums.length - k;
            } else {
                adjust -= k;
            }
            // System.out.println(adjust);
            if (nums[adjust] == target) {
                return adjust;
            } else if (nums[adjust] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
}