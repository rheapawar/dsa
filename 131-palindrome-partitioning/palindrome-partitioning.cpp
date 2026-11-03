class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> curr;
        string p = "";
        helper(res, curr, s, p, 0);
        return res;
    }
            //now consider whether the optimal way to do this is to build forward or build from the center of each
        //nono u are doing recursion on where you decide to split the word, so the two conditions would be to either partion here or to continue going and then if you are partitioning, you would need to check if the word up till that partition is a palindrome and then also start building a palindrome thing out of whatever comes after
        /*step by step plan
        at the top check if it is a palindrome

        then need to make decision of whether or not to add the next character or to create a partition here, if we are creating a partition then reset the curr otherwise

        wait so we can have it where we decide a partition and simulateneously then check if the word before is a palindrome and start buildign the new one.
        */

        /*general idea is to oh basically have a loop where we want to decide when to partition a word and then push it back into the vector partition and then choose where to go next */

        //consider the element curr
    /*idea is that if you want to */

        void helper(vector<vector<string>> &res, vector<string> &curr, string &s, string &p, int idx){
            if(idx == s.length()){
                res.push_back(curr);
                return;
            }
            
            for(int i = idx; i < s.length(); i++){
                p.push_back(s[i]);
                if(isPalindrome(p)){
                    curr.push_back(p);
                    string n = "";
                    helper(res, curr, s, n, i+1);//cut that there and start building a new word
                    curr.pop_back();
                }
            }
        }

        bool isPalindrome(string &p){
            int i = 0;
            int j = p.length()-1;
            while(i < j){
                if(p[i] != p[j]) return false;
                i++;
                j--;
            }
            return true;
        }
    
};