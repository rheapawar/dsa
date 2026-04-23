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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int h = 0;
        if(root->right && root->left) h = 1 + max(maxDepth(root->right), maxDepth(root->left));
        else if(root->right) h = 1 + maxDepth(root->right);
        else if(root->left) h = 1 + maxDepth(root->left);
        else h = 1;
        return h;
    }
};