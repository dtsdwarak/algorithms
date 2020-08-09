# include <iostream>
# include <vector>

using namespace std;

int main() {

  int x = 90;
  vector<int> arr = {11,13,20,22,29,4,6,8,9,10};
  int high=arr.size()-1, low=0,mid;
  
  while(low<=high) {
    mid = (high+low)/2;
    if (arr[mid] == x) {
      cout<<"Item found at "<<mid;
      exit(1);
    }
    if (arr[mid]<=arr[high]) {
      if (x > arr[mid] && x <= arr[high])
        low = mid +1;
      else
        high = mid -1;
    }
    else if (arr[mid] >= arr[low]) {
      if (x > arr[low] && x <= arr[mid])
        high = mid -1;
      else
        low = mid + 1;
    }
  }
  
  cout<<"Item not found";
}
