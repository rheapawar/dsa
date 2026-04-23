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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        deque<TreeNode*> d;
        d.push_back(root);
        while(!d.empty()){
            int s = d.size();
            vector<int> x(s);
            if(res.size() % 2 == 0){
                for(int i = 0; i < s; ++i){
                    TreeNode *n = d.front();
                    d.pop_front();
                    x[i] = n->val;
                    if(n->left) d.push_back(n->left);
                    if(n->right) d.push_back(n->right);
                }
            }
            else{
                for(int i = s - 1; i>=0; --i){
                    TreeNode *n = d.front();
                    d.pop_front();
                    x[i] = n->val;
                    if(n->left) d.push_back(n->left);
                    if(n->right) d.push_back(n->right);
                }
            }   
                        res.push_back(x);  

            }     
        return res;
    }
};