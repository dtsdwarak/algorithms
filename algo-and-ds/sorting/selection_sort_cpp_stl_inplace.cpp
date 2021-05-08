# include <iostream>
# include <array>

using namespace std;

int main() {

  array<int,9> arr = {9,8,7,6,5,4,3,2,1};
  int index;
  
  for(int i = 0; i<arr.size(); i++) {
    index = i;
    for (int j = i+1 ; j < arr.size() ; j++) {
      if (arr[j] < arr[index]) {
        index = j;
      }
    }
    swap(arr[i],arr[index]);
  }
  
  for(auto i : arr) {
    cout<<i<<" ";
  }
}
