class WordDistance {
private:
    unordered_map<string, vector<int>> indices;
    int num_words;
public:
    WordDistance(vector<string>& wordsDict){
        for(int i = 0; i < wordsDict.size(); i++){
            indices[wordsDict[i]].push_back(i);
        }
        num_words = wordsDict.size();
    }
    
    int shortest(string word1, string word2) {
       int dist = num_words;
       int smallest = num_words;
       int i = 0;
       int j = 0;
       //handle special case if they are equal to each other
       while(i < indices[word1].size() && j < indices[word2].size()){
            dist = abs(indices[word1][i] - indices[word2][j]);
            if(indices[word1][i] > indices[word2][j]) j++;
            else i++;
            smallest = min(smallest, dist);
            
       }
       return smallest;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */