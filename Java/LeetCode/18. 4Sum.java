class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> out = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 3; i++) {
            for (int j = nums.length - 1; j > 2; j--) {
                if (i != 0 && nums[i] == nums[i - 1])
                    continue;
                if (j != nums.length - 1 && nums[j] == nums[j + 1])
                    continue;
                int l = i + 1, r = j - 1;
                while (l < r) {
                    if (nums[i] + nums[l] + nums[r] + nums[j] > target) {
                        while (r > 0 && nums[r] == nums[r - 1])
                            r--;
                        r--;
                    } else if (nums[i] + nums[l] + nums[r] + nums[j] == target) {
                        ArrayList<Integer> nextOut = new ArrayList<>();
                        nextOut.add(nums[i]);
                        nextOut.add(nums[l]);
                        nextOut.add(nums[r]);
                        nextOut.add(nums[j]);
                        out.add(nextOut);
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

        }
        return out;
    }
}