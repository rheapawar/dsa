class Logger {
private:
    unordered_map<string, int> seen;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(seen.contains(message) && seen[message] + 10 > timestamp){
           return false;
        }
        seen[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */