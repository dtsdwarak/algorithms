/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;

// Vector output template
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

bool verifyIfValidPostOrder(vector<int> &v, int minIndex, int maxIndex) {
    
    if (minIndex == maxIndex)
        return true;
    
    // Identify the 1st place where value < ROOT
    int rootValue = v[maxIndex];
    int i = maxIndex-1;
    for(; i>=minIndex && v[i] > rootValue; i--);
    
    // Verify if left half of tree has values < ROOT
    for(int j = i; j>=minIndex; j--) {
        if (v[j] > rootValue)
            return false;
    }
    
    return verifyIfValidPostOrder(v, minIndex, i) && 
           verifyIfValidPostOrder(v, i+1, maxIndex-1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> postOrder = {1,4,3,2,7,6,9,8,5};
    
    cout<<verifyIfValidPostOrder(postOrder, 0, postOrder.size() - 1);
    return 0;
}
