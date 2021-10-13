class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> out = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length - 2;i++){
            if(i !=0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = nums.length-1;
            while(l<r){
                if(nums[i] + nums[l] + nums[r] > 0){
                    while(r > 0 && nums[r] == nums[r-1]) r--;
                    r--;
                }
                else if(nums[i] + nums[l] + nums[r] == 0){
                    ArrayList<Integer> nextOut = new ArrayList<>();
                    nextOut.add(nums[i]);
                    nextOut.add(nums[l]);
                    nextOut.add(nums[r]);
                    out.add(nextOut);
                    while(r > 0 && nums[r] == nums[r-1]) r--;
                    r--;
                }
                else{
                    while(l < nums.length-1 && nums[l] == nums[l+1]) l++;
                    l++;
                }
            }
        }
        return out;
    }
}