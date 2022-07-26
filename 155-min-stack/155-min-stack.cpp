class MinStack {
private:
    struct node {
        int val;
        int minVal;
        node* prev;
    };
    
    struct node *topp;
    
public:
    MinStack() {
        topp = nullptr;
    }
    
    void push(int val) {
        node* temp = new node;
        temp->val = val;
        
        //Basically the minVal in the node keeps track of the smallest value in the nodes previous
        if(topp == nullptr) {
            temp->minVal = val;
        } else {
            temp->minVal = min(topp->minVal,val);
        }
        
        temp->prev = topp;
        topp = temp;
    }
    
    void pop() {
        node* temp = topp;
        topp = temp->prev;
        delete temp;
    }
    
    int top() {
        return topp->val;   
    }
    
    int getMin() {
        return topp->minVal;
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