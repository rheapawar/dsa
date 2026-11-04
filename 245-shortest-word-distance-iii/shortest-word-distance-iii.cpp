class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
         int distance = wordsDict.size();
        int idx1 = -1;
        int idx2 = -1;
        bool same = (word1 == word2) ? true : false;
        bool updated = false;
        for(int i = 0; i < wordsDict.size(); i++){
            updated = false;
            if(same && wordsDict[i] == word1){
                if(idx1 < idx2) idx1 = i;
                else idx2 = i;
                updated = true;
            }
            else if(wordsDict[i] == word1){
                updated = true;
                idx1 = i;
            } 
            else if(wordsDict[i] == word2){
                idx2 = i;
                updated = true;
            }
            if(updated && idx1 != -1 && idx2 != -1){
                int d = abs(idx1 - idx2);
                distance = min(d, distance);
            }
        }
        return distance;
    }
};