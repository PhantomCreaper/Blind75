// 155. Min Stack
class MinStack {
private:
    stack<pair<int, int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minV;
        if(s.empty()){
            minV = val;
        } else{
            minV = min(val, s.top().second);
        }
        s.push({val, minV});

    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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
