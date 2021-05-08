# include <iostream>

using namespace std;

int choosePivot(int arr[], int& ll, int& ul) {

  int pivot = (ll + ul)/2;
  if (arr[ll]>arr[ul])
    swap(arr[ll],arr[ul]);
  if (arr[ll]>arr[pivot])
    swap(arr[ll],arr[pivot]);
  if (arr[pivot]>arr[ul])
    swap(arr[pivot],arr[ul]);
    
  return pivot;

}


void quicksort(int arr[], int ll, int ul) {

  if (ll>=ul) {
    return ;
  }
  
  int pivot = choosePivot(arr, ll, ul);
  int pivotValue = arr[pivot];
  
  int storeIndex = ll;
  
  // This is to backup the pivot value so it can restored.
  swap(arr[pivot],arr[ul]);
  
  for(int i=ll;i < ul; i++) {
    
    if (arr[i] < pivotValue) {
      swap(arr[i],arr[storeIndex]);
      storeIndex++;
    }
    
  }
  
  swap(arr[storeIndex],arr[ul]);
  
  quicksort(arr, ll, storeIndex);
  quicksort(arr, storeIndex + 1, ul);
}

int main() {

  int arr[] = {9,8,7,6,5,4,3,2,1};
  int size=sizeof(arr)/sizeof(arr[0]);
  
  quicksort(arr, 0, size - 1);

  for (auto i : arr)
    cout<<i<<" ";

 
}
