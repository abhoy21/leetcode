class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            mp[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
        
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int idx = mp[val];
            int last = v.back();
            v[idx] = last;
            v.pop_back();
            mp[last] = idx;
            mp.erase(val);
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int random = rand() % v.size();
        return v[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */