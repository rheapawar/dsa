class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> res;
        /*basic idea is to use s.find to find the first instance of string a and then within the range of k from a same for b, if either return npos, return res otherwise calculate i - j, if less than k, append, otherwise see if there is another instance of the word w the smaller index starting at the range gap, can only use each a once, but can use a b multiple times*/

        auto i = s.find(a);
        auto j = s.find(b);
        while(i != string::npos && j != string::npos){
            if(abs((int)i - (int)j) <= k){
                res.push_back(i);
                i = s.find(a, i+1);
            }
            else if(i < j) i = s.find(a, i+1);
            else j = s.find(b, j+1); 
        }
        return res;


    }
};