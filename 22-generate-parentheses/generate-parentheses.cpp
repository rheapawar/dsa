class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> perms;
        string perm;
        helper(n,0, perm, perms);
        return perms;
    }

    void helper(int o, int c, string &perm, vector<string> &res){
        if(o == 0 && c == 0){
            res.push_back(perm);
            return;
        }
        else{
            if (o >= 0){
                perm.push_back('(');
                helper(o-1, c+1, perm, res);
                perm.pop_back();
            }
            if (c > 0){
                perm.push_back(')');
                helper(o, c-1, perm, res);   
                perm.pop_back();
            }
        }
    }
    
};