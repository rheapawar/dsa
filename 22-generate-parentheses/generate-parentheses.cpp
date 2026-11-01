class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "(";
        generate(res, curr, n, n-1, n);
        return res;
        /*idea is that u need same number of open as close and for each open there must be a valid close after each opening bracket. so u need to keep track of each open parantheses that u have used so that the appropriate close can be applied */
        
        
    }

    void generate(vector<string> &res, string &curr, int n, int o, int c){
        if(curr.length() == 2*n){
            res.push_back(curr);
            return;
        }
        //choose to either add in an opening parantheses and if not, then add a close but only if there is an open to match it. so then maybe instead make the decision if we should add a close parantheses. if yes, then 

        if(o > 0){
            curr.push_back('(');
            generate(res, curr, n, o-1, c);
            curr.pop_back();
        }
        if(o < c){
            curr.push_back(')');
            generate(res, curr, n, o, c-1);
            curr.pop_back();
        }
        
    }
};