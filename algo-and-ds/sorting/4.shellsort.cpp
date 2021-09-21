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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr{4,1,4,8,2,7,9,12,545,74,8};
    
    int n = arr.size();
    
    for(int gap = n/2; gap>0; gap /= 2) {
            
        for(int i=gap; i<n; i++) {
            
            int j=i;
            for(;j>=gap && arr[j] < arr[j-gap]; j -= gap)
                swap(arr[j], arr[j-gap]);
        }
        
    }
    
    for(int i:arr)
        cout<<i<<" ";
    
    return 0;
}

