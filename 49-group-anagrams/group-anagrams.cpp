class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        res.reserve(strs.size());
        unordered_map<string, vector<string>> map;
        map.reserve(strs.size());
        for(const auto &x : strs){
            string a = x;
            sort(a.begin(), a.end());
            map[a].push_back(x);
        }
        for(auto it = map.begin(); it != map.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};