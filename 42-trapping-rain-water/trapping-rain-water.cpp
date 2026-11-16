class Solution {
public:
    int trap(vector<int>& height) {
        /*if right is larger than left, then left becomes the height*/
        int n = height.size();
        int left_max = 0;
        int right_max = n-1;
        int left = 0;
        int right = n-1;
        int water = 0;

        while(left < right){
            if(height[left] < height[right]){
                if(height[left] < height[left_max]){
                    water += (height[left_max] - height[left]);
                }
                else left_max = left;
                left++;
            }
            else{
                if(height[right] < height[right_max]){
                    water += (height[right_max] - height[right]);
                }
                else right_max = right;
                right--;
            }
        }
        return water;
    }
};