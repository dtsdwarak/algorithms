class Vector2D {

private:

    vector<int> flattenedList;
    int pointer;

public:
    Vector2D(vector<vector<int>>& vec) {


        for(int i=0; i<vec.size();i++) {
            for(int j=0;j<vec[i].size();j++) {
                flattenedList.push_back(vec[i][j]);
            }
        }

        pointer = -1;
 
    }
    
    int next() {
        if (hasNext()) {
            return flattenedList[++pointer];
        }
        return -501;
    }
    
    bool hasNext() {
        if (pointer + 1 < flattenedList.size())
            return true;
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
