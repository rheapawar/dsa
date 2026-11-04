class Solution {
public:
    int compress(vector<char>& chars) {
        /*general idea, traverse thru the elements and if the current element is equal to the last element, update streak variable, keep two indices, one for which element of the vector we are on, another for where we are writing into in the vector*/
        int write = 0;
        int i = 0;
        while(i < chars.size()){
            char curr = chars[i];
            int streak = 0;
            while(i < chars.size() && curr == chars[i]){
                i++;
                streak++;
            }
            chars[write++] = curr;
            if(streak > 1){
                string s = to_string(streak);
                for(char c : s){
                    chars[write++] = c;
                }
            }
            
        }
        return write;
    }
};