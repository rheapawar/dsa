class TimeMap {
private:
        unordered_map<string, vector<pair<int,string>>> map;
public:
/*potentially a hashmap with the largest prev timestamp for each key and then either a hashamp w the time stamps where the value is a nested hashmap with its val being the value or a vector where the index is the timestamp*/
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(map[key].empty()) return "";
        auto it = map[key].end();
        it--;
        while(it != map[key].begin() && it->first > timestamp){
            it--;
        }
        return (it->first <= timestamp) ? it->second : "";
}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */