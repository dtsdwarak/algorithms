class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        
        stack<int> s;
        
        for(int i: asteroids) {
            
            if (!s.empty() && s.top() > 0 && i < 0) {
                    
                bool currentAstroidDestroyed = false;
                
                while(!s.empty() && s.top() > 0) {
                    
                    if (s.top() == -1 * i) {
                        s.pop();
                        currentAstroidDestroyed = true;
                        break;
                    }
                    else if (s.top() < -1 * i) {
                        s.pop();
                    }
                    else if (s.top() > -1 * i) {
                        currentAstroidDestroyed = true;
                        break;
                    }
                
                }
                
                if (!currentAstroidDestroyed) {
                    s.push(i);                    
                }

            }
            else
                s.push(i);
            
        }
        
        vector<int> ans(s.size());
        int i = s.size() - 1;
        while(!s.empty()) {
            ans[i] = s.top();
            i--;
            s.pop();
        }
        
        return ans;
        
    }
};
