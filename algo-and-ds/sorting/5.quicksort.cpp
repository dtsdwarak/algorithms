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

int partition(vector<int> &arr, int low, int high) {
  
  int pivot = arr[high], i=low-1;
  
  for(int j=low; j<=high-1; j++) {
    
    if (arr[j] <= pivot) {
      
      i++;
      swap(arr[j], arr[i]);
      
    }
  }
  
  swap(arr[i+1], arr[high]);
  return i+1;
  
}

void quicksort(vector<int> &arr, int low, int high) {

  if (low<high) {
      
    int m = partition(arr, low, high);
    quicksort(arr, low, m-1);
    quicksort(arr, m+1, high);
  }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr{10,9,8,7,6,5,4,3,2,1};
    
    quicksort(arr, 0, arr.size()-1);
    
    for(int i: arr)
      cout<<i<<" ";
}
