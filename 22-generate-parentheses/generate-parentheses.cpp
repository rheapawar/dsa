class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> perms;
        helper(n,0, "", perms);
        return perms;
    }

    void helper(int o, int c, string perm, vector<string> &res){
        if(o == 0 && c == 0){
            res.push_back(perm);
            return;
        }
        else{
            if (o >= 0) helper(o-1, c+1, perm + "(", res);
            if (c > 0) helper(o, c-1, perm + ")", res);   
            }
        }
    
};