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
        /*key idea is to go thru and for every node discovered on a level, add to  queue so we process in order of discovery, loop thru
        
        in order to zigzag, could use two queues and traverse one as stack one as queue or another approach would be to use a deque and then once every thing has been added for a level, keep track of the total number and then push from front or push from back, do outer while loop till empty and then do */

        
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> d;
        d.push_back(root);
        int idx = 0;
        while(!d.empty()){
            int n = d.size();
            res.emplace_back();
            for(int i = 0; i < n; i++){
                
                if(idx % 2 == 0){
                    TreeNode *t = d.front();
                    d.pop_front();
                    res[idx].push_back(t->val);
                    if(t->left) d.push_back(t->left);
                    if(t->right) d.push_back(t->right);
                }
                else{
                    TreeNode *t = d.back();
                    res[idx].push_back(t->val);
                    d.pop_back();
                    if(t->right) d.push_front(t->right);
                    if(t->left) d.push_front(t->left);
                }
               
            }
            idx++;
        }
        return res;
        
    }
};