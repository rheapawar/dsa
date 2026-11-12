class Solution {
public:
    string frequencySort(string s) {
        /*general idea is create a vector of the counts of the chars and then go thru - genuinely just do a vector w the chars as the index, then create a vector of pairs, sort from greatest to least and then remake the string, hmm okay so u cant do raw character count, maybe do a map and then do a vector of pairs*/
        unordered_map<char, int> counts;
        for(auto c : s) counts[c]++;

        vector<pair<int, char>> freqs;
        for(auto &[c, val] : counts){
            freqs.push_back({val,c});
        }    
        sort(freqs.begin(), freqs.end(), greater<>());
        string res = "";
        for(int i = 0; i < freqs.size(); i++){
            int count = freqs[i].first;
            char c = freqs[i].second;
            while(count > 0){
                res.push_back(c);
                count--;
            }
        }
        return res;
        
    }
};