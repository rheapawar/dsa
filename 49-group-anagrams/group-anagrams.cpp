class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        res.reserve(strs.size());
        unordered_map<string, vector<string>> map;
        map.reserve(strs.size());
        for(const auto &x : strs){
            map[getKey(x)].push_back(x);

        }
        for(auto it = map.begin(); it != map.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }

    string getKey(string s){
        int counts[26] = {};
        for(char c : s){
            counts[c - 'a']++;
        }

        string a = "";
        for(int i = 0; i < 26; i++){
            if(counts[i] > 0){
                a += char('a' + i);
                a += to_string(counts[i]);
            }
        }
        return a;
    }
};