# include <bits/stdc++.h>

using namespace std;


int countOfSubsets(vector<int>& arr, int sum) {

    int n = arr.size();
    
    // Initialization
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
    
    // Initialize 1st column to zero since you can have empty subsets that have 0 sum value
    for(int i=0; i<n+1; i++)
        t[i][0] = 1;

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if (arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];

}


int main() {

    
    vector<int> arr1{2, 3, 7, 8, 10};
    vector<int> arr2{1, 5, 11, 5};
    vector<int> arr3{13, 9};

    cout<<countOfSubsets(arr1, 15)<<endl;
    cout<<countOfSubsets(arr2, 11)<<endl;
    cout<<countOfSubsets(arr3, 22)<<endl;
    cout<<countOfSubsets(arr3, 13)<<endl;

}
