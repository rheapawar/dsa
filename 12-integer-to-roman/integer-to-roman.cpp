class Solution {
public:
    string intToRoman(int num) {
        /*rough idea would be to subtract the element each time and then maybe keep a pointer to track how many times the prev roman numeral has been repeated?? but then the number shoudl be is using sequence of if statements ratchet
        
        when it reaches count of 3, need to upgrade symbol and switch to left
        
        use hash table?*/
        vector<pair<int, string>> map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string res;
        for(auto it = map.begin(); it != map.end(); it++){
            while(num >= it->first){
                res += it->second;
                num -= it->first;
            }
        }
        return res;
    }
};