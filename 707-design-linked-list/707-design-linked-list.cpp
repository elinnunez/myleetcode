struct node {
    int val;
    node* next;
    node(){
        val = 0;
        next = nullptr;
    }
    node(int v) {
        val = v;
        next = nullptr;
    }
};

class MyLinkedList {
private:
    node* head;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0) {
            return -1;
        }
        node* cur = head;
        int idx = 0;
        while(idx != index) {
            cur = cur->next;
            idx++;
        }
        
        return cur->val;
    }
    
    void addAtHead(int val) {
        node* temp = new node(val);
        if(head == nullptr) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    
    void addAtTail(int val) {
        node* temp = new node(val);
        if(head == nullptr) {
            head = temp;
        } else {
            node* cur = head;
            while(cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = temp;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) {
            return;
        }
        
        if(index <= 0) {
            addAtHead(val);
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        
        node* temp = new node(val);
        
        node* cur = head;
        
        int idx = 0;
        
        while(idx != index-1) {
            idx++;
            cur = cur->next;
        }
        
        temp->next = cur->next;
        cur->next = temp;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) {
            return;
        }
        
        if(index == 0) {
            head = head->next;
            size--;
            return;
        }
        
        node* cur = head;
        
        int idx = 0;
        
        while(idx != index-1) {
            cur = cur->next;
            idx++;
        }
        
        if(idx == size-1) {
            cur->next = nullptr;
            size--;
            return;
        }
        
        node* temp = cur->next;
        
        if(temp) {
            cur->next = temp->next;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */