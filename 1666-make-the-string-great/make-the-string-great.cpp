class Solution {
public:
    string makeGood(string s) {
        if(s.length() == 1) return s;
        string res;
        /*general idea is to make sure that the gap between the ascii codes isnt the particular number --> abs 32??*/
        for(char c : s){
            if(!res.empty() && abs(c - res.back()) == 32){
                res.pop_back();
            }
            else res.push_back(c);
        }       
        return res;
            
    }
};