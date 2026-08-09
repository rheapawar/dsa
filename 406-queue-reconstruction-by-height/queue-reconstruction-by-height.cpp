class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      sort(people.begin(), people.end(), [](const vector<int> &a, vector<int> &b){
        if(a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1];
      });
      vector<vector<int>> queue(people.size(), vector<int>(2, -1));
      for(int i = 0; i < people.size(); i++){
        int y = 0;
        int j = 0;
        for( ; j < people.size(); j++){
            if(queue[j][0] == -1){
                if (y < people[i][1]) y++;
                else break;
            }
        }
        
        queue[j] = people[i];

      }
      return queue;
    }
};