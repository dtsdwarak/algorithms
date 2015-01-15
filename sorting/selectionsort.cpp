# include <iostream>

using namespace std;

int returnSize(int b[]){
    cout<<"\n"<<sizeof(b);
    cout<<"\n"<<sizeof(b[0]);
    return (sizeof(b)/sizeof(b[0]));
}


int main(){
    int arr[]={1,6,2,5,89,3,0,2,54,26},small;
    for(int i=0;i<10;i++){
        small = i;
        for(int j=i;j<10;j++){
            if(arr[small]>arr[j])
            small = j;
        }
        int temp = arr[small];
        arr[small]= arr[i];
        arr[i]=temp;
    }
    
    cout<<"\n";
    for(int i=0;i<10;i++)
    cout<<" "<<arr[i];
    return 0;
}

