class Solution {
public:
    void rotate2(vector<int>& nums, int k) {
        int n = 0;
        int s = nums.size();
        for(int i = 0; i < k;i++){
            int temp = nums[i];
            int at = (i+k)%s;
            while(at != i){
                swap(nums[at], temp);
                at = (at+k)%s;
                n++;
            }
            swap(nums[at], temp);
            n++;
            if(n == nums.size())break;
        }    
    }

    // simpler solution
    
    void reverseRange(vector<int>& nums, int l, int r){
        for(int i=0; i<(r-l+1)/2;i++){
            swap(nums[l+i], nums[r-i]);
        }
    }
    
    void rotate(vector<int>& nums, int k){
        //reverse list
        k %= nums.size();
        reverseRange(nums, 0, nums.size()-1);
        reverseRange(nums, 0, k-1);
        reverseRange(nums, k, nums.size()-1);
    }


};