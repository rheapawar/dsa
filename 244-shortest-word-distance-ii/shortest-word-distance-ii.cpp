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
       const vector<int> &one = indices[word1];
       const vector<int> &two = indices[word2];
       int dist = num_words;
       int smallest = num_words;
       int i = 0;
       int j = 0;
       //handle special case if they are equal to each other
       while(i < one.size() && j < two.size()){
            dist = abs(one[i] - two[j]);
            if(one[i] > two[j]) j++;
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