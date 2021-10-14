class Solution {
    public void sortColors(int[] nums) {
        int l = 0, r = nums.length - 1;
        for (int i = 0; i <= r;) {
            if (nums[i] == 0) {
                int temp = nums[i];
                nums[i] = nums[l];
                nums[l] = temp;
                l++;
                if (l > i)
                    i = l;
            } else if (nums[i] == 1)
                i++;
            else {
                int temp = nums[i];
                nums[i] = nums[r];
                nums[r] = temp;
                r--;
            }

        }
    }
}