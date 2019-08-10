#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> has;
        for(int next:nums){
            has.insert(next);
        }
        for(int count=0;count<nums.size();count++){
            if(has.find(target-nums[count])!=has.end()){
                for(int count2=count+1;count2<nums.size();count2++){
                    if(nums[count2]==target-nums[count]){
                        vector<int> output{count2,count};
                        return output;
                    }
                }
            }
        }
        
    }
};