# include <iostream>
# include <vector>
# include <climits>

using namespace std;

double medianOfTwoSortedArrays(vector<int> &input1, vector<int> &input2) {
  
  if (input1.size() > input2.size())
    return medianOfTwoSortedArrays(input2, input1);
    
  
  int low=0;
  int high=input1.size();
  
  while(low <= high) {
    
    int partitionX = (low + high)/2;
    int partitionY = (input1.size() + input2.size() + 1)/2 - partitionX;
    
    int maxLeftX = (partitionX == 0) ? INT_MIN : input1[partitionX -1];
    int minRightX = (partitionX == input1.size())? INT_MAX : input1[partitionX];
    
    int maxLeftY = (partitionY == 0)? INT_MIN : input2[partitionY - 1];
    int minRightY = (partitionY == input2.size()) ? INT_MAX : input2[partitionY];
    
    if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
      
      if ((input1.size() + input2.size()) % 2 == 0)
        return (double) (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
      else
        return (double) max(maxLeftX, maxLeftY);
    }
    
    if (maxLeftX > minRightY)
      high = partitionX - 1;
    else
      low = partitionX + 1;
  }
  
  return 1.0D;
  
}


int main() {

  vector<int> input1{10,20,30,40,50};
  vector<int> input2{11,13,39,57,86,91};
  
  
  cout<<"Median value = "<<medianOfTwoSortedArrays(input1, input2);
  
  return 0;
}
