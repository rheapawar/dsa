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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /*would u not want to find the original way to */
        if(!subRoot) return true;
        if(!root || !subRoot) return false;
        if(validate(root, subRoot)) return true;
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
         
    }

    bool validate(TreeNode* root, TreeNode *subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val){
            return validate(root->right, subRoot->right) && validate(root->left, subRoot->left);
        }
        else return false;
    }
};