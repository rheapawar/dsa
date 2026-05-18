class MinStack {
private:
    vector<int> q;
    int min = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        q.push_back(val);
        if(val < min) min = val;
    }
    
    void pop() {
        int x = q.back();
        q.pop_back();
        if(x == min){
            if(q.empty()) min = INT_MAX;
            else{
                min = q[0];
                for(int i = 1; i < q.size(); i++){
                    if(q[i] < min) min = q[i];
                }
            }
        }
    }
    
    int top() {
        return q.back();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */