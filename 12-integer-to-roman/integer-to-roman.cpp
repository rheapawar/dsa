class Solution {
public:
    string intToRoman(int num) {
        /*rough idea would be to subtract the element each time and then maybe keep a pointer to track how many times the prev roman numeral has been repeated?? but then the number shoudl be is using sequence of if statements ratchet
        
        when it reaches count of 3, need to upgrade symbol and switch to left
        
        use hash table?*/

        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;

        int i = 0;
        while(num > 0){
            if(num >= nums[i]){
                num -= nums[i];
                res += roman[i];
            }
            else i++;
        }
        return res;
    }
};