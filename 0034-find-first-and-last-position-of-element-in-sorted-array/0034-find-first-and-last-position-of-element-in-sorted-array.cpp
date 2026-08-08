class Solution {
public:
    int firstOccurance(vector<int> &arr, int  target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans  = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) {
                ans = mid;
                high = mid-1;
            }
            else if(target > arr[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    int lastOccurance(vector<int> & arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) {
                ans = mid;
                low = mid+1;

            }
            else if(target > arr[mid]) {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    } 
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurance(nums, target);
        if(first == -11) {
            return {-1, -1};
        }
        int last = lastOccurance(nums, target);
        if(last == -1) {
            return {-1, -1};
        }
        return {first, last};
    }
};