class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
         int distance = wordsDict.size();
        int idx1 = -1;
        int idx2 = -1;
        
        for(int i = 0; i < wordsDict.size(); i++){
            if(wordsDict[i] == word1 && word1 == word2){
                if(idx1 < idx2) idx1 = i;
                else idx2 = i;
            }
            else if(wordsDict[i] == word1) idx1 = i;
            else if(wordsDict[i] == word2) idx2 = i;
            if(idx1 != -1 && idx2 != -1){
                int d = abs(idx1 - idx2);
                distance = min(d, distance);
            }
        }
        return distance;
    }
};