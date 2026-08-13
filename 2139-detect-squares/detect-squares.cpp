class DetectSquares {
private:
    int counts[1001][1001] = {0};  
    vector<int> x_vals[1001];
public:
/*unordered_set not allowed bc of duplicates, maybe hash_map instead?? so when a point is looked up, just return 2 * the curr results, if two diff points that could be used that it would be 4x, essentially like 2 choose 1 for each option

when searching for the number of points, need a way to iterate over, but 1000 possible values for x and y so can't look up

what if vector sorted by x coordinate? 

but then what about looking up match w y coordinate?

they gave a max tho, is iterating over 3000 possible?

what if i do a hashmap between y values and then have a vector with all the potential x values that have been inserted, so then when i find a matching x value, just need to loop thru the vector and see if there are matching x values

this creates O(N) for the thing as opposed to a constant fixed number tho
*/
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        if(counts[point[0]][point[1]] == 0) x_vals[point[0]].push_back(point[1]);
        counts[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0];
        int y1 = point[1];
        for(int y2 : x_vals[x1]){
            if (y1 == y2) continue;
            else{
                int count_y2 = counts[x1][y2];
                int d = abs(y2 - y1);
                if(x1 - d >= 0){
                    res += counts[x1 - d][y1] * counts[x1 - d][y2] * count_y2;
                }
                if(point[0] + d < 1001){
                    res += counts[x1 + d][y1] * counts[x1 + d][y2] * count_y2;
                }
            }
        }
        return res;
                //if u encounter one coordinate w the same, then need to search for if 
        
            
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */