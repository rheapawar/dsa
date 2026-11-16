class Solution {
public:
    bool isValid(string s) {
       /*idea is that every open bracket needs a close and the one opened most recently needs to be the first one closed again*/ 
        stack<char> bracket;
       for(char p : s){
            if(p == '(') bracket.push(')');
            else if(p == '[') bracket.push(']');
            else if(p == '{') bracket.push('}');
            else{
                if(bracket.empty() || p != bracket.top()) return false;
                bracket.pop();
            }      
        }
        return bracket.empty();
    }
};