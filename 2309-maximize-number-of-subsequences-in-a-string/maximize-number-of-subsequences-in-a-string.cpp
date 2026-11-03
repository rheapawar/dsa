class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        /*general idea, try both characters in the pattern string take the max, also to determine the max number of times it can occur, at each moment, need to consider for pattern[0], the number of times the second element has occured (traverse from the back) and then for pattern[1], the number of times the other element has occured before it at each position, keep track of both the number of pattern[0] that have occured at each index and then also the number of pattern[1] that has occured at each index, potentially a counter?? or would a vector work better, for pattern[0], choosing the spot that maximizes the number of the of the second char after it is peak, like where (first_forwards+1)*second_backwards is at itsgreatest or second_backwads+1 * first_forwards is at its max, can also add the element before or after the end of the word as well
        
        when reading problem statement, write any important edge cases specified in the problem statement at the top of the ide
        
        oh choosing where to add according to the rest of the numbers does not matter because the base number initially is the same for the two so u just need to see where adding another will maximize */

        

        long long first = 0;
        long long second = 0; 
        long long existing = 0;
        for(char c : text){
            if(pattern[1] == c){
                existing += first;
                second++;
            }
            if(pattern[0] == c)first++;
        }
        
        return existing + max(first, second);
    }
};