class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        /*initial ideas, go thru and create a map with the username and all the places and timestamps of where they visited - any used w greater than 3, create potential pattern 
        
        shold i create vector with all the possible patterns? or a map - lets do map 
        to create a pattern, consider implementing 
        how to create hte patterns - we are gonna want to do 
        
        */
        unordered_map<string, vector<pair<int, string>>> users;

        map<vector<string>, int> patterns;
        for(int i = 0; i < username.size(); i++){
            users[username[i]].push_back({timestamp[i], website[i]});
        }

        for(auto it = users.begin(); it != users.end(); it++){
            sort(it->second.begin(), it->second.end());
            set<vector<string>> user_patterns = userPatterns(it->second);
            for(auto &p : user_patterns){
                patterns[p]++;
            }
        }

        int largest = 0;
        vector<string> res;
        for(const auto &[p, count] : patterns){
            if(count > largest){
                largest = count;
                res = p;
            }
        }
        return res;

    }

    set<vector<string>> userPatterns(vector<pair<int,string>> &patterns){
        set<vector<string>> unique;
        int m = patterns.size();
        for(int i = 0; i < m-2; i++){
            for(int j = i+1; j < m-1; j++){
                for(int k = j + 1; k < m; k++){
                    unique.insert({patterns[i].second, patterns[j].second, patterns[k].second});
                }
            }
        }
        return unique;
    }
};