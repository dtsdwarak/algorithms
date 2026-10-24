# include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int w, int n) {
	
	// base condition
	if (n == 0 || w == 0)
		return 0;
	
	if (wt[n-1] <= w) {
		return max((val[n-1] + knapsack(wt, val, w-wt[n-1], n-1)), knapsack(wt, val, w, n-1));
	}
	else
		return knapsack(wt, val, w-wt[n-1], n-1);
	
}

int main() {

	int n=4;
	vector<int> wt{1, 3, 5, 7};
	vector<int> val{1, 5, 7, 9};
	
	cout<<knapsack(wt, val, 15, 4);
	

}
