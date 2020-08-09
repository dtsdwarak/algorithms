# include <iostream>

/*

medianOfThreePivot for choosing the pivot element based on:
http://en.wikipedia.org/wiki/Quicksort#Choice_of_pivot

Algorithm for the same from:
http://stackoverflow.com/a/13996665

Basic QuickSort algorithm:
http://en.wikipedia.org/wiki/Quicksort#Algorithm

*/

namespace medianOfThreePivot{
    
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    int choosePivot(int arr[], int& ll, int& ul){
        int mid = (ll+ul)/2;
        if(arr[ll]>arr[ul])
            swap(arr[ll],arr[ul]);
        if(arr[ll]>arr[mid])
            swap(arr[ll],arr[mid]);
        if(arr[mid]>arr[ul])
            swap(arr[mid],arr[ul]);
        return mid;
    }
}

using namespace medianOfThreePivot;
using namespace std;

int partition(int arr[], int& ll, int& ul){
    int pivotIndex = choosePivot(arr,ll,ul);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex],arr[ul]);
    int storeIndex = ll;
    for(int i=ll;i<ul;i++){
       if(arr[i]<pivotValue){
        swap(arr[i],arr[storeIndex]);
        storeIndex++;
       } 
    }
    swap(arr[storeIndex],arr[ul]);
    return storeIndex;
}

void quickSort(int arr[], int ll, int ul){
    if(ll<ul){
        int p = partition(arr,ll,ul);
        quickSort(arr,ll,p);
        quickSort(arr,p+1,ul);
    }
}

int main(){
    int arr[] = {100,99,98,97,96,95,94,93,92,91,90};
    int size=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    cout<<"\nArray after Sorting\n";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}