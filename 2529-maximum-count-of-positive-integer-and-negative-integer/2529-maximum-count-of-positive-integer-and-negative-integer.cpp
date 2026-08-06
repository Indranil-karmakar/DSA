class Solution {
public:
    int lower_bound(vector<int> & nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = nums.size();
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] >= 0) {
                ans = mid;
                 high = mid-1;
            }
            else{
                low = mid+1;
            }
            
        }
        return ans;
        
    }
    int upper_bound(vector<int> & nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = nums.size();
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] > 0) {
                ans = mid;
                 high = mid-1;
            }
            else{
               low = mid+1;
            }
            
        }
        return ans;
        
    }
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums);
        int pos = nums.size() - upper_bound(nums);
        return max(neg, pos);
    }
};