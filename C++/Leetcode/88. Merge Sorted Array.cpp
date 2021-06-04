//create new array, before setting it to nums1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> lol;
        for(int i=0,j=0;i<m||j<n;){
            if(i==m){
                lol.push_back(nums2[j++]);
            }
            else if(j==n){
                lol.push_back(nums1[i++]);
            }
            else if(nums1[i]<nums2[j]){
                lol.push_back(nums1[i++]);
            }
            else{
                lol.push_back(nums2[j++]);
            }
        }
        nums1 = lol;
    }
};