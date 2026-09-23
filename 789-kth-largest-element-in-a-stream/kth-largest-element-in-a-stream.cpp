class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cap = 0;
    KthLargest(int k, vector<int>& nums) {
        /*idea, prolly have min + max heap, min heap to store top 1 - k elements, and then max heap to store all number smaller than k - if something popped f - never remove any elements, only add, so then just keep singular min heap of size k and if a new element is added and it is larger, pop top and insert new*/
        cap = k;
        for(int i = 0; i < nums.size(); i++){
            if(pq.size() >= k){
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            else pq.push(nums[i]);
        }       
    }
    
    int add(int val) {
        if(pq.size() < cap) pq.push(val);
        else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */