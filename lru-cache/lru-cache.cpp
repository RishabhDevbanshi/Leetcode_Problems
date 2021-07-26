class LRUCache {
public:
    class node{
      public:
        node *prev , *next;
        int key,val;
        
        node(int key,int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    
    int cap;
    unordered_map<int,node*> mp;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    void delNode(node *temp)
    {
        node *nextNode = temp->next;
        node *prevNode = temp->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }
    
    void addNode(node *temp)
    {
        node *headn = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = headn;
        headn->prev = temp;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            node *curr = mp[key];
            int val = curr->val;
            
            delNode(curr);
            addNode(curr);
            mp[key] = head->next;
            
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            node *curr = mp[key];
            mp.erase(key);
            delNode(curr);
        }
        else if(mp.size() == cap)
        {
            node *curr = tail->prev;
            mp.erase(curr->key);
            delNode(curr);
        }
        
        addNode(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */