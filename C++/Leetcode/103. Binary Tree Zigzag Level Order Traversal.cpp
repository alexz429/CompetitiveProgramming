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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> q;
        stack<TreeNode*> back;
        if(root){
            back.push(root);
        }
        vector<vector<int>> out;
        bool flag = false;
        while(!back.empty()){
            flag = !flag;
            q = back;
            back = stack<TreeNode*>();
            vector<int> next;
            while(!q.empty()){
                TreeNode* get = q.top();
                q.pop();
                next.push_back(get->val);
                if(flag){
                   if(get->left){
                    back.push(get->left);    
                    }
                    if(get->right){
                        back.push(get->right);
                    } 
                }
                else{
                    if(get->right){
                        back.push(get->right);
                    }
                    if(get->left){
                        back.push(get->left);    
                    } 
                }
                
            }
            out.push_back(next);
        }
        return out;
    }
};