class Solution {
    public int threeSumClosest(int[] nums, int target) {
        List<List<Integer>> out = new ArrayList<>();
        Arrays.sort(nums);
        int goal = -1000000;
        for (int i = 0; i < nums.length - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.length - 1;
            while (l < r) {
                if (Math.abs(goal - target) > Math.abs(nums[i] + nums[l] + nums[r] - target)) {
                    goal = nums[i] + nums[l] + nums[r];
                }
                if (nums[i] + nums[l] + nums[r] > target) {
                    while (r > 0 && nums[r] == nums[r - 1])
                        r--;
                    r--;
                } else {
                    while (l < nums.length - 1 && nums[l] == nums[l + 1])
                        l++;
                    l++;
                }
            }
        }
        return goal;
    }
}