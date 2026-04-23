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
    struct help{
        TreeNode* n;
        int lvl;
        help(TreeNode *n, int lvl) : n(n), lvl(lvl){}
    };
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {{root->val}};
        vector<vector<int>> res;
        deque<help> d;
        d.push_back(help(root, 0));
        int curr = -1;
        while(!d.empty()){
            help h = d.front();
            d.pop_front();
            int i = h.lvl;
            TreeNode *t = h.n;
            if(curr != i){
                curr = i;
                vector<int> x;
                res.push_back(x);
            }
            res[i].push_back(t->val);
            if(t->left) d.push_back(help(t->left, i+1));
            if(t->right) d.push_back(help(t->right, i+1));
        }
        return res;
    }
};