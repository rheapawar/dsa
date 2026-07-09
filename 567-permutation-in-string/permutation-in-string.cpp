class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> counts(26, 0);
        for(int i = 0; i < s1.length(); i++){
            counts[s1[i] - 'a']++;
        }
        int left = 0;
        int s = s1.length();
        for(int i = 0; i < s2.length(); i++){
            int x = s2[i] - 'a';
            while(counts[x] == 0 && left < i){
                counts[s2[left]-'a']++;
                s++;
                left++;
            }
            if(counts[x]>0){
                counts[x]--;
                s--;
                if(s == 0) return true;
            }
            else left = i + 1;
            
        }
        return false;
    }
};