class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int, int> mpp;
        // for(int i=0; i<nums.size(); i++) {
        //     int a = nums[i];
        //     int found = target - a;
        //     if(mpp.find(found) != mpp.end()) {
        //         return {mpp[found], i};
        //     }
        //     mpp[a] = i;
        // }
        // return {};
        
        int n = nums.size(); 
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        int left = 0, right = n-1;
        sort(arr.begin(), arr.end());
        while(left < right) {
            int sum = arr[left].first + arr[right].first;
            if(sum == target) {
                return {arr[left].second, arr[right].second};
            }
            if(sum < target) {
                left++;
            }
            else right--;

        }
        return {};
    }
};