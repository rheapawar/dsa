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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *n = root;
        queue<TreeNode*> q;
        helper(root, q);
        q.pop();
        while(!q.empty()){
            n->right = q.front();
            q.pop();
            n = n->right;
        }
        
        
    }

    void helper(TreeNode* root, queue<TreeNode*> &q){
        q.push(root);
        if(root->left) helper(root->left, q);
        if(root->right) helper(root->right,q);
        root->right = nullptr;
        root->left = nullptr;
        return;
    }
};