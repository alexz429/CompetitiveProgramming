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
    bool recurse(TreeNode* at, int target, int sum){
        if(!at)return false;
        sum += at->val;
        if(!at->left&&!at->right){
            if(target==sum)return true;
            return false;
        }
        return recurse(at->left, target, sum)||recurse(at->right, target, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recurse(root, targetSum, 0);
    }
};