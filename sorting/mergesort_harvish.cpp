/*
ID : harvish
LANG : C++11
PROG : mergesort
*/
#include <bits/stdc++.h>
#define mp make_pair;
#define push push_back;
#define pop pop_back;

typedef long long ll;
#define pii pair<int,int>

#define fore(i,n) for(int i=0;i<n;i++)
#define forv(i,v) for(int i=0;i<v.size();i++)

using namespace std;

void mergesort(int a[], int p, int r){
//	cout<<"p="<<p<<" r="<<r<<endl;

	int res[r-p+1];
	int q=0;
	if(p>=r) {
		return;
	}
	else {
		q=(p+r)/2; //pivot
	
		// individually sorting
		mergesort(a, p, q);
		mergesort(a, q+1, r);
		
		// merging
		int i=p,j=q+1;
		fore(k,r-p+1)
		{
			if(a[i] < a[j] && i<=q )
			{
				res[k]=a[i];
				i++;
			}  else	if(a[i] > a[j] && j<=r ) {
				res[k]=a[j];
				j++;
			} else {
				res[k] = a[i];
				i++;
			}
		}
		fore(k, r-p+1)
		{
			a[k+p] = res[k];
		}
	}
 }
int main() {
	int arr[] = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int p=0,r=size;

	mergesort(arr,p,r-1);
	
	cout<<"\nResult: ";
	fore(i, size) cout<<arr[i]<<" ";
	
	return 0;
}
