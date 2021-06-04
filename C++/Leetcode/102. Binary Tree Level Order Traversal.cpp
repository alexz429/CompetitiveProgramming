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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> back;
        if(root){
            back.push(root);
        }
        vector<vector<int>> out;
        
        while(!back.empty()){
            q = back;
            back = queue<TreeNode*>();
            vector<int> next;
            while(!q.empty()){
                TreeNode* get = q.front();
                q.pop();
                next.push_back(get->val);
                if(get->left){
                    back.push(get->left);    
                }
                if(get->right){
                    back.push(get->right);
                }
            }
            out.push_back(next);
        }
        return out;
    }
};