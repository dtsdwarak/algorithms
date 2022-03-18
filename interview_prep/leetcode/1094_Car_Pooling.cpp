class Solution {
    
    void insertValueInMap(int &key, int value, map<int, int> &mapStruct) {
        if (mapStruct.find(key) != mapStruct.end()) {
            mapStruct[key] += value;
        } 
        else
            mapStruct.insert({key, value});
    }
    
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        map<int, int> locationCapacityPairs;
        
        for(auto i: trips) {
            insertValueInMap(i[1], i[0], locationCapacityPairs);
            insertValueInMap(i[2], -i[0], locationCapacityPairs);
        }
        
        for(auto i: locationCapacityPairs) {
            cout<<i.first<<"--"<<i.second<<"\n";
        }
        
        int totalCount = 0;
        for(auto i: locationCapacityPairs) {
            totalCount += i.second;
            if (totalCount < 0)
                totalCount = 0;
            if (totalCount > capacity)
                return false;
        }
        
        return true;
        
    }
};
