class Solution {
public:
    
    string entityParser(string text) {
        
        unordered_map<string, string> umap {
            {"&quot", "\""},
            {"&apos", "'"},
            {"&amp", "&"},
            {"&gt", ">"},
            {"&lt", "<"},
            {"&frasl", "/"}
        };

        
        int i=0;
        int n = text.length();
        
        string ans;
        
        while(i < n) {
            
            
            if (text[i] == '&') {
                
                string prefix;
                
                while(i<n && text[i] == '&') {
                    prefix += text[i];
                    i++;
                }
                
                ans += prefix.length() > 1 ? prefix.substr(0, prefix.length()-1) : "";
                
                
                string s = "&";
                
                while(i<n && text[i] != ';') {
                    s += text[i];
                    i++;
                }
                
                if (umap.find(s) == umap.end())
                    ans += s + ';';
                else                
                    ans += umap[s];
            }
            
            else 
                ans += text[i];
            
            i++;
            
        }
        
        return ans;
        
    }
};
