class Solution {
public:
    string removeKdigits(string num, int k) {
        //essentially would it not be removing the k largest digits from the number?, dont count leading zeroes, hmm might need to accordingly undo element removal, need to also consider only numbers greater than 0 to remove, removing 0 does nothing
        //process string into a stack where while stack.size() < k, push the elements in but make sure to have the smallest at the top and then for every element after that if it is a larger number than top of stack, pop and replace w mine. then at the end go thru and erase all members in the stack from the string using the string erase func, wait just do a vector and then when u reach k elements sort it to be descneding and then consistenly check back another way to do it would be to use a stack and if the number if larger than 0, would
        if(k >= num.length()) return "0";

        string res = "";
        int i = 0;
        for(; i < num.length() ; i++){
            while(!res.empty() && res.back() > num[i] && k > 0){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
            
        }
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        i = 0;
        while(i < res.length() && res[i] == '0') i++;
        res = res.substr(i);
        return (res.empty()) ? "0" : res;

    }
};