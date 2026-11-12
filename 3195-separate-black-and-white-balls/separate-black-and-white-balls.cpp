class Solution {
public:
    long long minimumSteps(string s) {
        /*wait is it not just that every time u have a black on the left of a white, you would need to move it at least one over??
        so then count the number of white by looping thru once, then u know until what index u would need to move an element to. 

        1010101

        0001111

        okay so 3 white balls, so index 4 to the end, then go thru from beginning and subtract next black from curr black increment to num steps and then icnrement index of next black, could instead have it where every time u see a white,
        
        */
        long long steps = 0;
        long long blacks = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1') blacks++;
            else steps += blacks;
        }
        /*
        long long black_idx = white;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1' && i < black_idx){ 
                steps += black_idx - i;
                black_idx++;
            }
        }*/
        return steps;
    }
};