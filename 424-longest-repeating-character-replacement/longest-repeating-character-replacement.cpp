class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> letters(26, 0);
        int left = 0;
        int m = 0;
        int n = 0; 
        for(int i = 0; i < s.length(); i++){
            int x = s[i] - 'A';
            ++letters[x];
            m = max(m, letters[x]);
            if(i - left + 1 - m > k){
                int y = s[left] - 'A';
                letters[y]--;
                left++;
            }
            n = max(n, i - left + 1);
        }
        return n;
    }
};