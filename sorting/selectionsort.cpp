# include <iostream>

using namespace std;

int main(){
    int arr[]={9,8,7,6,5,4,3,2,1}, min,temp;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        
        //Swapping elements
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    
    //Printing for output
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    return 0;
}