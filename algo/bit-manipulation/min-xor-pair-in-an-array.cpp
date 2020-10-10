/*
	author: dtsdwarak
    Prood/Logic - https://youtu.be/OZ2jghS0t24?t=400
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;
typedef unsigned uint;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr = {1,18,19,56,76,-1,-99};
    sort(arr.begin(), arr.end());
    
    int minXor = INT_MAX;
    
    for(uint i=0; i<arr.size() - 1; i++)
        minXor = min(minXor, arr[i] ^ arr[i+1]);
    
    return minXor;
}
