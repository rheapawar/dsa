class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*hashmap of sorted strings w key being sorted*/

        unordered_map<string, vector<string>> map;
        for(string s : strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(s);
        }
        
        vector<vector<string>> res;
        res.reserve(strs.size());

        for(auto it = map.begin(); it != map.end(); it++){
            res.push_back(it->second);
        }

        return res;
    }
};