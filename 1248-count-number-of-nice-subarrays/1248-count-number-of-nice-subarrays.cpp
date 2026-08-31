class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0;
        int count = 0;
        int odd = 0;

        for (int r = 0; r < nums.size(); r++) {

            if (nums[r] % 2 != 0) {
                odd++;
            }

            while (odd > k) {
                if (nums[l] % 2 != 0) {
                    odd--;
                }
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};