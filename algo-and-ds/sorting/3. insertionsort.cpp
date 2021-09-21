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
    
    for(unsigned int i=1;i<arr.size();i++) {
        
        // toBePutIntoSortedSection = arr[i];
        int j=i;
        for(; j>0 && arr[j] < arr[j-1]; j--)
            swap(arr[j],arr[j-1]);
    }
    
    for(int i: arr)
        cout<<i<<" ";
    
}

