class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        vector<string> words;
        words.reserve(s.length());
        string word;

        while(ss >> word){
            words.push_back(word);
        }
        string res = "";
        for(int i = words.size()-1; i >= 0; i--){
            res += words[i];
            if(i != 0) res += " ";
        }
        return res;
    }
};