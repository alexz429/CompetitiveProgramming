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
    int min = 1000000;
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        help(root, 1);
        return min;
    }
    void help(TreeNode* at, int step){
        if(at == nullptr||step>=min) return;
        if(at->left == nullptr && at->right == nullptr){
            min = step;
            return;
        }
        help(at->left, step+1);
        help(at->right, step+1);
    }
};