#include <iostream>
# include <vector>

using namespace std;

int main() {
 
 vector<int> arr = {11,13,20,22,29,4,6,8,9,10};
 
 int n = arr.size();
 int high=arr.size()-1, low=0,mid;
 
 if (arr[low] <= arr[high]) {
  cout<<"Array already sorted";
  exit(1);
 }
 
 while(low<=high) {
 
  mid = (high+low)/2;
  
  int next = (mid + 1) % n;
  int prev = (mid -1 + n) % n;
  
  if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
    cout<<"Array rotated "<<mid + 1<<" times";
    exit(1);
  }
  
  else if (arr[mid] <= arr[high]) {
    high = mid -1 ;
  }
  
  else
    low = mid + 1;
 }
  
}
