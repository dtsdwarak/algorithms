struct Cell {
    int row;
    int col;
};

class Excel {

private:
    vector<vector<int>> mat;
    vector<vector<vector<Cell>>> formula;
    int rows;
    int cols;

    int getCol(char c) {
        return c-'A';
    }

    int getRow(int c) {
        return c-1;
    }

    // Helper to parse individual strings like "A1" or "A1:B2"
    vector<Cell> parseFormula(const string& s) {
        vector<Cell> output;
        size_t colon_pos = s.find(':');
        
        if (colon_pos == string::npos) {
            // Case 1: Single cell e.g., "A1" or "A11"
            int ci = getCol(s[0]);
            int ri = getRow(stoi(s.substr(1)));
            output.push_back({ri, ci});
        } else {
            // Case 2: Range e.g., "A1:B2" or "A11:B26"
            string first = s.substr(0, colon_pos);
            string second = s.substr(colon_pos + 1);
            
            int sci = getCol(first[0]);
            int sri = getRow(stoi(first.substr(1)));
            
            int dci = getCol(second[0]);
            int dri = getRow(stoi(second.substr(1)));
            
            for (int i = sri; i <= dri; i++) {
                for (int j = sci; j <= dci; j++) {
                    output.push_back({i, j});
                }
            }
        }
        return output;
    }

public:
    Excel(int height, char width) {
        rows = height;
        cols = getCol(width) + 1;
        mat = vector<vector<int>>(rows, vector<int>(cols, 0));
        formula = vector<vector<vector<Cell>>>(rows, vector<vector<Cell>>(cols, vector<Cell>{}));
    }
    
    void set(int row, char column, int val) {
        mat[getRow(row)][getCol(column)] = val;
        formula[getRow(row)][getCol(column)].clear();
    }
    
    int get(int row, char column) {
        
        int r = getRow(row);
        int c = getCol(column);

        if (formula[r][c].size() == 0)
            return mat[r][c];

        int sum = 0;
        for(auto& c: formula[r][c]) {
            sum += get(c.row+1, 'A'+c.col);
        }
        return sum;
    }
    
    int sum(int row, char column, vector<string> numbers) {
        int r = getRow(row);
        int c = getCol(column);
        
        formula[r][c].clear();

        for (const auto& str : numbers) {
            vector<Cell> cells = parseFormula(str);
            formula[r][c].insert(formula[r][c].end(), cells.begin(), cells.end());
        }

        // Calculate and return the live updated evaluation
        return get(row, column);
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
