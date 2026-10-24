# include <bits/stdc++.h>

using namespace std;


bool checkIfSubsetSumExists(vector<int>& arr, int sum) {

    int n = arr.size(); // input arrauy selection
    vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));

    for(int i=0; i<n+1; i++)
        t[i][0] = true;

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if (arr[i-1] <= sum)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];

}

bool verifyIfEqualSumPartitionExists(vector<int>& arr) {

    int sum=0;
    for(const int& num : arr) {
        sum += num;
    }

    if (sum & 1)
        return false;

    return checkIfSubsetSumExists(arr, sum/2);

}


int main() {

    
    vector<int> arr1{2, 3, 7, 8, 10};
    vector<int> arr2{1, 5, 11, 5};
    vector<int> arr3{13, 9};

    cout<<(verifyIfEqualSumPartitionExists(arr1) ? "true" : "false")<<endl;
    cout<<(verifyIfEqualSumPartitionExists(arr2) ? "true" : "false")<<endl;
    cout<<(verifyIfEqualSumPartitionExists(arr3) ? "true" : "false")<<endl;

}
