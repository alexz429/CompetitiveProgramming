/*
hashmap stores duplicates

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> store;
        for(int i=0;i<nums.size();i++){
            if(store.find(nums[i])!=store.end()){
                nums.erase(nums.begin()+i);
                i--;//deleted node, must set pointer back by 1 to not skip over anything
            }
            else{
                store.insert(nums[i]);
            }
        }
        return nums.size();
    }
};