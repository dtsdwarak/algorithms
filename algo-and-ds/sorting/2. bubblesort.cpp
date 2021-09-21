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
    
    vector<int> arr{10,9,8,7,6,5,4,3,2,1};
    
    for(unsigned int i=0; i<arr.size()-1;i++) {
    
      for(unsigned  int j=0;j<arr.size()-i-1;j++) {
        
          if (arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
      }
    
    }
    
    for(int i: arr)
      cout<<i<<" ";
    
}

