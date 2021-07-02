/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //take the middle node out of a given range to create the new node, and recursively call the function again, attaching the resulting nodes to the left and right
    TreeNode* create(vector<int>& nums, int l, int r){
        if(l<0||r>=nums.size()||l>r)return nullptr;
        return new TreeNode(nums[(l+r)/2], create(nums, l, (l+r)/2-1), create(nums, (l+r)/2+1, r));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size()-1);
    }
};