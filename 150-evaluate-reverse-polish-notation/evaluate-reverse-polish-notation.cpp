class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        nums.reserve(tokens.size());

        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int num1 = nums.back();
                nums.pop_back();
                int num2 = nums.back();
                nums.pop_back();
                if(s == "+") nums.push_back(num1 + num2);
                else if(s == "-") nums.push_back(num2 - num1);
                else if(s == "*") nums.push_back(num2 * num1);
                else if(s == "/") nums.push_back(num2 / num1);
            }
            else nums.push_back(stoi(s));
        }
        return nums.back();
    }
};