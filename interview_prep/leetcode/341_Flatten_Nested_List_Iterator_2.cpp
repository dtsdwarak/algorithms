/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {

private:

    vector<int> nestedList_;
    int i=0;

    vector<int> parseList(const vector<NestedInteger>& list) {

        vector<int> output;

        for(const auto& item: list) {
            if (item.isInteger()) {
                output.push_back(item.getInteger());
            } 
            else {
                vector<int> result = parseList(item.getList());
                output.insert(output.end(), result.begin(), result.end());
            }
        }

        return output;

    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nestedList_ = parseList(nestedList);
        i=0;
    }
    
    int next() {
        return nestedList_[i++];
    }
    
    bool hasNext() {
        return (i < nestedList_.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
