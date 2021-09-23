// https://www.geeksforgeeks.org/merge-sort-with-o1-extra-space-merge-and-on-lg-n-time/
// https://www.geeksforgeeks.org/in-place-merge-sort/


# include <iostream>

using namespace std;


void merge(int arr[], int subarr1[], int subarr2[], int s1length, int s2length, int arrlength){
    int i=0, j=0, k=0;

    while(i<s1length && j<s2length){
        if(subarr1[i]<subarr2[j]){
            arr[k]=subarr1[i];
            i++;
            k++;
        }
        else{
            arr[k]=subarr2[j];
            j++;
            k++;
        }
    }
    while(i<s1length){
        arr[k]=subarr1[i];
        i++;
        k++;
    }
    while(j<s2length){
        arr[k]=subarr2[j];
        j++;
        k++;
    }

}

void split(int arr[], int subarr[], int p, int q){
    int k=0;
    for(int i=p;i<=q;i++){
        subarr[k]=arr[i];
        k++;
    }
}

void mergesort(int arr[], int p, int r){
    if(p==r)
        return;
    else{
        int q = (p+r)/2;
        int *subarr1 = new int[q+1];
        int *subarr2 = new int[q+1];
        
        //To split the array into two halves - Divide
        split(arr,subarr1,p,q);
        split(arr,subarr2,q+1,r);
 
        
        //Recursive Sort
        mergesort(subarr1,p,q);
        mergesort(subarr2,0,r-q-1);
 
        //Merge the obtained result
        merge(arr,subarr1,subarr2,q-p+1,r-q,r-p+1);
        delete(subarr1);
        delete(subarr2);
    }
}

int main(){
    int arr[] = {1,6,42,5,89,3,0,2,54,26};
    int p=0,r=9;

    mergesort(arr,p,r);

    for(int i=0;i<=r;i++)
        cout<<arr[i]<<" ";
    return 0;
}
