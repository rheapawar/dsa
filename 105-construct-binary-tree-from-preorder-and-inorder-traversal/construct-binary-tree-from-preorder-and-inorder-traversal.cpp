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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0, preorder.size() -1, preorder, inorder);
    }

    TreeNode* helper(int start, int l, int r, vector<int> &preorder, vector<int> &inorder){
        if(l > r) return nullptr;
        TreeNode *root = new TreeNode(preorder[start]);
        int index = find(inorder.begin() + l, inorder.begin() + r + 1, root->val) - inorder.begin();
        root->left = helper(start + 1, l, index -1, preorder, inorder);
        root->right = helper(start + index - l + 1, index + 1, r, preorder, inorder);

        return root;
    }
};