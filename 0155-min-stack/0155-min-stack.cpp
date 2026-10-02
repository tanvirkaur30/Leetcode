class MinStack {
public:
    stack<long long>st;
    long long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else if(value<mini){
            st.push(2LL*value-mini);
            mini = value;
        }else st.push(value);
    }
    
    void pop() {
        if(st.empty()) return ;
        long long x=st.top();
        st.pop();
        if(x<mini){
            mini = 2LL*mini-x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        else if(st.top()<mini) return mini;
        else return st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;
        else return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */