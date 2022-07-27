class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        
        if(!q1.empty()){
            while(q1.front()!=q1.back()){
                q2.push(q1.front());
                q1.pop();
            }
            int front = q1.front();
            q1.pop();
            return front;
        }
    else{
        while(q2.front()!=q2.back()){
                q1.push(q2.front());
                q2.pop();
            }
            int front = q2.front();
            q2.pop();
            return front;
        
    }
    }
    
    int top() {
        if(!q1.empty()) return q1.back();
        return q2.back();
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */