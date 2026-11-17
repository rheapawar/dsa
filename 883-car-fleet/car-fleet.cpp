class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*is there some math we can do to determine whether two cars will meet at some time t - should i loop over units of time until all cars have reached the target? ooh maybe a stack of all the present cars and positions  each element in the stack represents a fleet and so at each time period, we should be, hmm so process in terms of closest to the target so lemme do like a vector of pairs and then sort, then calculate and push into a stack then for each element after if the number of turns they take will be smaller then they comine i think*/

        vector<pair<int,int>> combined(speed.size());
        for(int i = 0; i < position.size(); i++){
            combined[i] = {position[i], speed[i]};
        }
        sort(combined.begin(), combined.end(), greater());
        stack<double> hours;
        //10,2 8,4 5,1 3,1 0,1
        // target - pos / speed
        // 2/2 = 1, 4/4 = 1, 7, 
        for(int i = 0; i < combined.size(); i++){
            double h = (target - combined[i].first)/static_cast<double>(combined[i].second);
            if(hours.empty() || h > hours.top()) hours.push(h);
        }
        int fleets = 0;
        while(!hours.empty()){
            fleets++;
            hours.pop();
        }
        return fleets;
    }
};