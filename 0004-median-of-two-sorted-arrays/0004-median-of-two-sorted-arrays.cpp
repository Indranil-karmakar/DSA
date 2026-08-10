class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0, high = n1;

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1  = (cut1 == 0)  ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int left2  = (cut2 == 0)  ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition found
            if (left1 <= right2 && left2 <= right1) {

                // Odd total length
                if ((n1 + n2) % 2 == 1)
                    return max(left1, left2);

                // Even total length
                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }

            // Move left
            else if (left1 > right2) {
                high = cut1 - 1;
            }

            // Move right
            else {
                low = cut1 + 1;
            }
        }

        return 0.0; // Never reached
    }
};