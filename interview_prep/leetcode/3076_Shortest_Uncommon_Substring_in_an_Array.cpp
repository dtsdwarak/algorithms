class Solution {

private:



public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        
        int n = arr.size();
        vector<string> ans(n, "");

        // Iterate over all strings
        for(int i=0; i<arr.size(); i++) {

            int ssize = arr[i].size();
            
            // Evalute all string lengths
            for(int j=1; j <= ssize && ans[i].empty(); j++) {

                string best_sub = "";
                
                // Evaluate all start positions
                for(int l=0; l <= ssize-j; l++) {

                    string sub = arr[i].substr(l, j);

                    bool is_uncommon = true;

                    // Now check for the string as substring across all strings
                    for(int k=0; k<arr.size(); k++) {
                        
                        // Ignore current string
                        if (k==i)
                            continue;

                        if (arr[k].find(sub) != string::npos) {
                            is_uncommon = false;
                            break;
                        }
                    }

                    if (is_uncommon) {
                        if (best_sub == "" || sub < best_sub)
                            best_sub = sub;
                    }
                }
                if (best_sub != "")
                    ans[i] = best_sub;
            }
        }
        return ans;
    }
};
