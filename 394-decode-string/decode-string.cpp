class Solution {
public:
    string decodeString(string s) {
        string pattern = "";
        stack<string> ss;
        stack<int> cs;
        int k = 0;
        for(char c : s){
            if(isdigit(c)) k = k*10 + (c - '0');
            else if(c == '['){
                cs.push(k);
                ss.push(pattern);
                pattern = "";
                k = 0;
            }
            else if(c == ']'){
                string decoded = ss.top();
                ss.pop();
                for(int count = cs.top(); count > 0; count--){
                    decoded += pattern;
                }
                cs.pop();
                pattern = decoded;

            }
            else{
                pattern += c;
            }
        }
        return pattern;
    }
};