class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int left = 0, right = n - 1;

        // Find the pivot: the index of the smallest value
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int pivot = left;

        // Binary search with pivot adjustment
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int realMid = (mid + pivot) % n; // shifted index

            if (nums[realMid] == target) {
                return realMid;
            } else if (nums[realMid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
