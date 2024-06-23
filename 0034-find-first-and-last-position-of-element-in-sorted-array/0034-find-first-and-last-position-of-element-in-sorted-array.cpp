class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1); // Initialize result with -1 for both positions
        if (nums.empty()) return result;

        // Find the first occurrence of target
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                if (mid == 0 || nums[mid - 1] != target) {
                    result[0] = mid;
                    break;
                } else {
                    high = mid - 1;
                }
            }
        }

        // Find the last occurrence of target
        low = 0;
        high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    result[1] = mid;
                    break;
                } else {
                    low = mid + 1;
                }
            }
        }

        return result;
    }
};
