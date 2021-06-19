class Solution {
public:
    string simplifyPath(string path) {
        
        string dir;
        stack<string> s;
        
        for(int i=0; i<path.length(); i++) {
            
            if(path[i] == '/') {
                if (dir != "") {
                    
                    if (dir == "..") {
                        if (!s.empty())
                            s.pop();   
                    }
                    else if (dir != ".")
                        s.push(dir);
                    dir = "";
                }
                continue;
            }
            else 
                dir += path[i];
            
        }
        
        if (dir == "..") {
            if (!s.empty())
                s.pop();   
        }
        else if (dir != "." && dir != "")
            s.push(dir);
        
        
        dir = "";
        while(!s.empty()) {
            dir = "/" + s.top() +  dir;
            s.pop();
        }
        
        return dir == "" ? "/" : dir;
        
    }
};
