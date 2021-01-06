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
/*
Three base cases:
If both trees empty, return null
If one tree empty, simply return the other tree
Otherwise, add their sums, and recursively call mergeTrees on their left/right nodes to build merged tree donw the line.
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr&&t2==nullptr)return nullptr;
        if(t1==nullptr)return t2;
        if(t2==nullptr)return t1;
        return new TreeNode(t1->val+t2->val, mergeTrees(t1->left, t2->left), mergeTrees(t1->right, t2->right));
    }
};