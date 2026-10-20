class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /*as soon as operator is encounterd for two numbers, you can proceed with the actual operation, note: using strings not chars here so cannot use isdigit or - '0', have to use stoi*/
        stack<int> nums;
        for(const auto &s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if(s == "+") nums.push(num1 + num2);
                else if(s == "-") nums.push(num1 - num2);
                else if(s == "*") nums.push(num1 * num2);
                else nums.push(num1/num2);
            }
            else nums.push(stoi(s));
        }
        return nums.top();
    }
};