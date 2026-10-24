# include <bits/stdc++.h>

using namespace std;


bool checkIfSubsetSumExists(vector<int>& arr, int sum) {

    int n = arr.size(); // input arrauy selection
    vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));

    // Initialization
    // for(int j=0; j<sum+1; j++)
    //     t[0][j] = false;
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



int main() {

    int sum = 28;
    vector<int> arr{2, 3, 7, 8, 10};

    cout<<(checkIfSubsetSumExists(arr, sum) ? "true" : "false")<<endl;

}
