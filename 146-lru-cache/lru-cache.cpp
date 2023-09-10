class LRUCache {
public:
    class node{
        public:
        int val;
        int key;
        node* prev;
        node* next;
        node(int l, int r)
        {
            key = l;
            val = r;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* first)
    {
        node* t = head->next;
        head->next = first;
        first->prev = head;
        t->prev = first;
        first->next = t;
    }

    void deletenode(node* ele)
    {
        node* delprev = ele->prev;
        node* delnext = ele->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            node* t = mp[key];
            int ans = t->val;
            mp.erase(key);
            deletenode(t);
            addnode(t);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            node* t = mp[key];
            mp.erase(key);
            deletenode(t);
        }
        if(mp.size() == cap)
        {
            node* t = tail->prev;
            mp.erase(t->key);
            deletenode(t);
        }
        addnode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */