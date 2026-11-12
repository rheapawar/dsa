class Solution {
public:
    string frequencySort(string s) {
        /*general idea is create a vector of the counts of the chars and then go thru - genuinely just do a vector w the chars as the index, then create a vector of pairs, sort from greatest to least and then remake the string, hmm okay so u cant do raw character count, maybe do a map and then do a vector of pairs, thing about how u can be inventive -- used a string so he could push back each character that is used instead of needing to use a vector inside of a vector*/
        int counts[256];
        for(auto c : s) counts[c - '0']++;

        int n = s.size();
        vector<string> buckets(n+1);
        for(int i = 0; i < 256; i++){
            if(counts[i] > 0) buckets[counts[i]].push_back('0' + i);
        }
        s.clear();
        for(int i = buckets.size()-1; i >= 0; i--){
            for(int j = 0; j < buckets[i].size(); j++){
                int count = i;
                while(count > 0){
                    s.push_back(buckets[i][j]);
                    count--;
                }
            }
        }
        return s;
       
        
    }
};