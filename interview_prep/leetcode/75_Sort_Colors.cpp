class Solution {

    
    int getPartition(vector<int>& arr, int low, int high) {
        
        int pivot=arr[high], i=low-1;
        for(int j=low; j<=high-1; j++) {
            
            if (arr[j] <= pivot) {
                
                i++;
                swap(arr[j], arr[i]);
            }
        }
        
        swap(arr[i+1], arr[high]);
        return i+1;
        
    }
    
    void quicksort(vector<int>& arr, int low, int high) {
        
        if (low<high) {
            
            int mid = getPartition(arr, low, high);
            quicksort(arr, low, mid-1);
            quicksort(arr, mid+1, high);
        }
        
    }
    
    
public:
    void sortColors(vector<int>& nums) {
        
        quicksort(nums, 0, nums.size()-1);
        
    }
};
