class Solution {
public:
    int maxArea(vector<int>& height) {
        /*do a thing w max area and at every point which ever one is shorter, move that pointer and then compare the max*/

        int max_water = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            int water = (min(height[left],height[right]))*(right-left);
            max_water = max(water, max_water);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max_water;
    }
};