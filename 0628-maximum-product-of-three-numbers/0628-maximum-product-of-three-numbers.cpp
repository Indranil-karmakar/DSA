class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
            int prod1 = nums[n-1] * nums[n-2] * nums[n-3];
            int prod2 = nums[0] * nums[1] * nums[n-1];
            int maxi = max(prod1, prod2);
            return maxi;
            
        
        
    }
};