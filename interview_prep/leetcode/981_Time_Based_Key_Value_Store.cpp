class TimeMap {
    
    unordered_map<string, vector<pair<int, string>>> mapData; 
    
    static bool compare(const pair<int, string> &a, const pair<int, string> &b) {
        return a.first < b.first;
    }
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        if (mapData.count(key))
            mapData[key].push_back(make_pair(timestamp, value));
        else
            mapData[key] = vector<pair<int, string>>{make_pair(timestamp, value)};
    }
    
    string get(string key, int timestamp) {

        auto t = upper_bound(begin(mapData[key]), end(mapData[key]), make_pair(timestamp, ""), compare);
        return t == mapData[key].begin() ? "" : prev(t)->second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
