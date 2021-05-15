class Solution {
public:
    
    tuple<int, string, int> parseLog(string str) {
        
        vector<string> strs(3);
        int j=0;
        string s;
        
        for(int i=0; i<str.length(); i++) {
            if (str[i] != ':') {
                s += str[i];
            } else {
                strs[j] = s;
                s = "";
                j++;
            }
        }
        
        strs[j] = s;
        
        return make_tuple(stoi(strs[0]),strs[1],stoi(strs[2]));
        
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> exclusiveTimes(n, 0);
        
        // Stack of functionId, action, timeStamp 
        stack<tuple<int, string, int> > s;
        
        int timePointer=0;
        
        for(auto i: logs) {
            
            tuple<int, string, int> log = parseLog(i);
                
            if (get<1>(log) == "start") {
                 if (!s.empty()) {
                     exclusiveTimes[get<0>(s.top())] += get<2>(log) - timePointer;
                     cout<<"\n Adding the value via 'start' node" <<get<2>(log) - get<2>(s.top())<<endl;
                 }
                timePointer = get<2>(log);
                s.push(log);
            }
            else if (get<1>(log) == "end") { 
                exclusiveTimes[get<0>(log)] += get<2>(log) - timePointer + 1;
                timePointer = get<2>(log) + 1;
                s.pop();
            }
        }
        
        return exclusiveTimes;
        
    }
};
