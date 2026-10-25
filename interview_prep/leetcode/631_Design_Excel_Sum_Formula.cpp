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

    int getCol(char c) { return c - 'A'; }
    int getRow(int r) { return r - 1; }

    vector<Cell> parseFormula(const string& s) {
        vector<Cell> output;
        size_t colon_pos = s.find(':');
        
        if (colon_pos == string::npos) {
            int ci = getCol(s[0]);
            int ri = getRow(stoi(s.substr(1)));
            output.push_back({ri, ci});
        } else {
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

    // Recursive helper that utilizes a memoization table
    int get_helper(int r, int c, vector<vector<int>>& memo) {
        if (formula[r][c].empty()) {
            return mat[r][c];
        }
        if (memo[r][c] != -1) {
            return memo[r][c];
        }
        
        int sum_val = 0;
        for (const auto& cell : formula[r][c]) {
            sum_val += get_helper(cell.row, cell.col, memo);
        }
        return memo[r][c] = sum_val;
    }

public:
    Excel(int height, char width) {
        rows = height;
        cols = getCol(width) + 1;
        mat = vector<vector<int>>(rows, vector<int>(cols, 0));
        formula = vector<vector<vector<Cell>>>(rows, vector<vector<Cell>>(cols, vector<Cell>{}));
    }
    
    void set(int row, char column, int val) {
        int r = getRow(row);
        int c = getCol(column);
        mat[r][c] = val;
        formula[r][c].clear();
    }
    
    int get(int row, char column) {
        // Create a temporary fresh cache for this query
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        return get_helper(getRow(row), getCol(column), memo);
    }
    
    int sum(int row, char column, vector<string> numbers) {
        int r = getRow(row);
        int c = getCol(column);
        formula[r][c].clear();

        for(const auto& cellFormula: numbers) {
            vector<Cell> cellsToAdd = parseFormula(cellFormula);
            formula[r][c].insert(formula[r][c].end(), cellsToAdd.begin(), cellsToAdd.end());
        }

       return get(row, column);
    }
};

