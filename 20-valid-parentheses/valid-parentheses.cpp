class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(char a : s){
            if( a =='[' || a == '(' || a == '{'){
                check.push(a);
            }
            else{
                if(check.empty()) return false;
                char b = check.top();
                check.pop();
                if((a == ')' && b != '(') || (a == '}' && b != '{') ||(a == ']' && b != '[')) return false;
        }
        }
        return check.empty();
    }
};