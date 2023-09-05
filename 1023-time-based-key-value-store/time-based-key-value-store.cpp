class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>> > mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())    return "";
        else if(mp[key][0].first > timestamp)   return "";
        else
        {
            int l = 0, h = mp[key].size() - 1;
            int res = -1;

            while(l <= h)
            {
                int mid = l + (h-l)/2;
                int ts = mp[key][mid].first;

                if(ts>timestamp) 
                    h = mid - 1;
                
                else
                    res = mid, l = mid + 1;
            }

            return res == -1 ? "" : mp[key][res].second;
        }

        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */