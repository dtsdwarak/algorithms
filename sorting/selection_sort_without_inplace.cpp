# include <iostream>

using namespace std;


int main() {

  int n=9,arr[]={9,8,7,6,5,4,3,2,1},small,smallIndex,arr2[n],arr2Index;
  smallIndex=0;
  arr2Index=0;
  
  while(n>0) {
 
  
    small = arr[0];
    
    for(int i=0;i<n;i++) {
      if (arr[i]<small) {
        small = arr[i];
        smallIndex = i;
      }
    }
    
    for(int i=smallIndex;i<n;i++) {
      arr[i] = arr[i+1];
    }
    
    n--;
    
    arr2[arr2Index++] = small;
    
  }
  
  for(int i=0;i<9;i++) {
    cout<<arr2[i]<<" ";
  }
  
  return 0;
  
}
