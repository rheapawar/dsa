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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        /*recurse down to the bottom of the tree and build ur way back up, keep left and right max counts + diameter between its two child nodes*/
        helper(root);
        return diameter;        

    }

    int helper(TreeNode *root){
        if(!root) return 0;
        int max_right = helper(root->right); 
        int max_left = helper(root->left);
        diameter = max(diameter, max_right + max_left);
        return 1 + max(max_right, max_left);
    }
    
};