class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> nextSE(n);
        vector<int> prevSE(n);
        vector<int> nextGE(n);
        vector<int> prevGE(n);
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            nextSE[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }
        for(int i=0; i<n; i++) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            prevSE[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        long long sumOfSubarrayMin = 0;
        
        for(int i=0; i<n; i++) {
            long long left = i - prevSE[i];
            long long right = nextSE[i] - i;
            sumOfSubarrayMin += 1LL * nums[i] * left * right;
        }
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            nextGE[i] = s.empty() ? n : s.top() ;
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }
        for(int i=0; i<n; i++) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            prevGE[i] = s.empty() ? -1 : s.top();
            s.push(i);
        } 
        long long sumOfSubarrayMax = 0;
        
        for(int i=0; i<n; i++) {
            long long left = i - prevGE[i];
            long long right = nextGE[i] - i;
            sumOfSubarrayMax += 1LL * nums[i] * left * right;
        }
        long long ans = 0;
        ans = ans + (sumOfSubarrayMax - sumOfSubarrayMin);
        return ans;
        

    }
};