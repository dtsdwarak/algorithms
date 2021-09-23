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


void heapify(vector<int>& arr, int size, int index) {

  int largest = index;
  int r = 2*index + 1;
  int l = 2*index;
  
  if (l<size && arr[l] > arr[largest])
    largest = l;
    
  if (r<size && arr[r] > arr[largest])
    largest = r;
    
  if (largest != index) {
    swap(arr[largest], arr[index]);
    heapify(arr,size,largest);
  }
}


void heapsort(vector<int>& arr) {


  int n = arr.size();
  
  for(int i=n/2; i>-1; i--)
    heapify(arr, n, i);

  for(int i=n-1; i>-1; i--) {
      swap(arr[i], arr[0]);
      heapify(arr, i, 0);
  }
  
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr{10,9,8,7,6,5,4,3,2,1};
    
    heapsort(arr);
    
    for(int i: arr)
      cout<<i<<" ";
}
