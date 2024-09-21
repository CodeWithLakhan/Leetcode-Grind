class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int val;
        if(s2.size()!=0)
        {
            val=s2.top();
            s2.pop();
            
        }
        else
        {
            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
            val=s2.top();
            s2.pop();
        }
        return val;
    }
    
    int peek() {
        int val;
        if(s2.size()!=0)
        {
            val=s2.top();
            
        }
        else
        {
            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
            val=s2.top();
        }
        return val;
    }
    
    bool empty() {
        if(s1.size()==0 && s2.size()==0) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */