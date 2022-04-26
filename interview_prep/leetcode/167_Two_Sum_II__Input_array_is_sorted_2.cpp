class Solution {
    
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int front=0, back=numbers.size()-1;
        
        while(front<back) {
            if (numbers[front] + numbers[back] == target)
                return vector<int>{front+1, back+1};
            else if (numbers[front] + numbers[back] < target)
                front++;
            else
                back--;
        }
        
        return vector<int>();
        
    }
};
