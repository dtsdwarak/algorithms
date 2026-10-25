class Solution {

    unordered_map<string, string> createParentChildRelationship(vector<vector<string>>& regions) {
        unordered_map<string, string> childToParentMap;

        for(const auto& region: regions) {
            string parent = region[0];
            for(int i=1; i<region.size(); i++) {
                childToParentMap[region[i]] = parent;
            }
        }

        return childToParentMap;

    }

public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        
        unordered_map<string, string> childToParentMap =  createParentChildRelationship(regions);

        string node = region1;
        vector<string> region1Path{node};

        while(childToParentMap.count(node)) {
            node = childToParentMap[node];
            region1Path.push_back(node);
        }

        node = region2;
        vector<string> region2Path{node};

        while(childToParentMap.count(node)) {
            node = childToParentMap[node];
            region2Path.push_back(node);
        }

        int i=region1Path.size()-1, j=region2Path.size()-1;
        while(i>=0 && j >=0 && region1Path[i] == region2Path[j]) {
            i--;
            j--;
        }

        return (i == region1Path.size()-1) ? region1Path[i] : region1Path[i+1];
        // return region1Path[i+1];

    }
};
