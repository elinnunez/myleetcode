struct node {
    int key;
    int val;
    node* prev = nullptr;
    node* next = nullptr;
    node(int _key, int _value) {
        key = _key;
        val = _value;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, node*> hmap;
    node* dumhead;
    node* dumtail;
public:
    
    LRUCache(int capacity) {
        cap = capacity;
        hmap.clear();
        dumhead = new node(0,0);
        dumtail = new node(0,0);
    }
    
    void addNode(node* nd) {
        if(dumhead->next == nullptr) {
            dumhead->next = nd;
            nd->prev = dumhead;
            nd->next = dumtail;
            dumtail->prev = nd;
        } else {
            nd->next = dumhead->next;
            dumhead->next->prev = nd;
            nd->prev = dumhead;
            dumhead->next = nd;
        }
    }
    
    void deleteNode(node* nd) {
        nd->prev->next = nd->next;
        nd->next->prev = nd->prev;
        nd->next = nullptr;
        nd->prev = nullptr;
    }
    
    
    int get(int key) {
        if(hmap.count(key)) {
            deleteNode(hmap[key]);
            addNode(hmap[key]);
            return hmap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hmap.count(key)) {
            hmap[key]->val = value;
            deleteNode(hmap[key]);
            addNode(hmap[key]);
        } else {
            hmap[key] = new node(key, value);
            addNode(hmap[key]);
            
            if(hmap.size() > cap) {
                hmap.erase(dumtail->prev->key);
                deleteNode(dumtail->prev);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */