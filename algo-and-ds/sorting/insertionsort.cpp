# include <iostream>

using namespace std;

int returnSize(int arr[]){
	return(sizeof(arr)/sizeof(arr[0]));
}

void swap(int&a, int&b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int arr[]={4,1,4,8,2,7,9,12,545,74,8};
	for(int i=1;i<11;i++){
		for(int j=i;j>0;j--){	
			if(arr[j]<arr[j-1]){
					swap(arr[j],arr[j-1]);
			}
		}
	}
    cout<<"\n";
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}