class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        res.reserve(s.length());
        vector<int> counts(26);
        for(int i = 0; i < p.length(); i++){
            counts[p[i] - 'a']++;
        }
        int left = 0;
        int streak = 0;
        for(int i = 0; i < s.length(); i++){
            int x = s[i] - 'a';
            if(counts[x] == 0){
                while(left < i && counts[x] == 0){
                    counts[s[left] - 'a']++;
                    streak--;
                    left++;
                }
            }
            if(counts[x] > 0){
                counts[x]--;
                streak++;
                if(streak == p.length()){
                    res.push_back(left);
                    counts[s[left] - 'a']++;
                    left++;
                    streak--;
                }
            }
            else left = i + 1;
        }
        return res;
    }
};