/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*in this question, dont know where the two nodes are but have to start and search for them - oh bst so u know where they will lie in comparison*/
        while(root){
            if(root->val > p->val && root->val > q->val) root = root->left;
            else if(root->val < p->val && root->val < q->val) root = root->right;
            else break;
        }
        return root;
    }
};