class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //just sort them first and then u can go thru them both at the same time and see which of them have both
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int idx1 = 0;
        int idx2 = 0;

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> res;

        while(idx1 < n1 && idx2 < n2){
            if(nums1[idx1] == nums2[idx2]){
                if(res.empty() || res.back() != nums1[idx1]) res.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            }
            else if(nums1[idx1] < nums2[idx2]) idx1++;
            else idx2++;
        }
        return res;
    }
};